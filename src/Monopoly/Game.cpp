#include "Monopoly/Game.h"
#include "Monopoly/MonopolyException.h"
#include "Monopoly/Randomizer/OneDice.h"
#include "Monopoly/Randomizer/PreDefined.h"
#include "Monopoly/Fields/Field.h"
#include "Monopoly/Fields/Property.h"
#include "Monopoly/Fields/Service.h"
#include "Monopoly/Fields/Luck.h"
#include "Monopoly/Player/Player.h"
#include "Monopoly/Player/AI/Greedy.h"
#include "Monopoly/Player/AI/Careful.h"
#include "Monopoly/Player/AI/Tactician.h"
#include <fstream>

namespace Monopoly {

    Game::Game(std::string filename) {
        loadGame(filename);
    }

    Game::~Game() {
        delete random;
    }

    void Game::loadGame(std::string filename) {
        std::ifstream file("games/" + filename + ".mg");
        if (!file.is_open()) {
            throw MonopolyException("File cant be opened");
        }

        std::string dice_type;
        file >> dice_type;

        if (dice_type == "one_dice") {
            random = new OneDice;
        } else if (dice_type == "pre_defined") {
            random = new PreDefined;
        } else {
            throw MonopolyException("Invalid dice type");
        }

        random->loadRandomizer(file);

        int fields_length;
        file >> fields_length;

        if (fields_length < 1) {
            throw MonopolyException("Not enough fields");
        }

        fields.resize(fields_length);

        for (int i = 0; i < fields_length; i++) {
            std::string type;
            file >> type;

            Field* field;

            if (type == "property") {
                field = new Property;
            } else if (type == "service") {
                field = new Service;
            } else if (type == "luck") {
                field = new Luck;
            } else {
                throw MonopolyException("Invalid field type");
            }

            field->loadField(file);
            fields[i] = field;
        }

        int starting_money;
        file >> starting_money;

        int player_number;
        file >> player_number;

        if (player_number < 1) {
            throw MonopolyException("Not enough players");
        }

        players.resize(player_number);

        for (int i = 0; i < player_number; i++) {
            std::string name;
            file >> name;
            std::string type;
            file >> type;

            Player* player = new Player(name, starting_money);

            if (type == "greedy") {
                player->setBrain(new Greedy);
            } else if (type == "careful") {
                player->setBrain(new Careful);
            } else if (type == "tactician") {
                player->setBrain(new Tactician);
            //} else if (type == "human") {
            //    player->setBrain(new Human);
            } else {
                throw MonopolyException("Invalid AI type");
            }

            players[i] = player;
        }
    }

    bool Game::gameTick() {
        tick++;

        Player* currentPlayer = players[nextPlayer];
        int diceRoll = random->DiceRoll();
        int newpos = currentPlayer->getCurrentPosition() + diceRoll;
        while (newpos >= fields.size()) {
            currentPlayer->finishedRound();
            newpos -= fields.size();
        }
        currentPlayer->stepTo(newpos, fields[newpos]);

        if (!currentPlayer->isStillPlaying()) {
            // kiesett a jatekbol
            for (int i = 0; i < fields.size(); i++) {
                if(Property* v = dynamic_cast<Property*>(fields[i])) {
                    if (v->isMine(currentPlayer)) {
                        v->reset();
                    }
                }
            }
        }

        bool cpi = nextPlayer;

        do {
            nextPlayer++;
            while (nextPlayer >= players.size()) {
                nextPlayer -= players.size();
            }
            if (cpi == nextPlayer) {
                return false;
            }
        } while (!players[nextPlayer]->isStillPlaying());

        return true;
    }

    void Game::printGame(Printer& printer) {
        printer.writeln("Tick " + toStr(tick) + ":");

        int max_cells = 5;
        int cell_width = 20;

        sbl::vector<sbl::vector<std::string> > strings;
        strings.resize(fields.size());

        for (int i = 0; i < fields.size(); i++) {

            std::string line_0 = "UNKNOWN FI";
            std::string line_1 = "";
            std::string line_2 = "";
            std::string line_3 = "";

            if(Property* v = dynamic_cast<Property*>(fields[i])) {
                line_0 = "PROPERTY";
                line_3 = "-" + toStr(v->getUpgradePrice()) + "/" + toStr(v->moneyChange());
                if (v->isSold()) {
                    /*line_2 = "SOLD";
                    if (v->hasHouse()) {
                        line_2 += " + HSE";
                    }*/
                    line_2 = v->getOwner()->getName();
                }
            }
            if(Service* v = dynamic_cast<Service*>(fields[i])) {
                line_0 = "SERVICE";
                line_3 = "-" + toStr(v->getServiceFee());
            }
            if(Luck* v = dynamic_cast<Luck*>(fields[i])) {
                line_0 = "LUCK";
                line_3 = "+" + toStr(v->getGift());
            }

            line_1 = "";
            for (int j = 0; j < players.size(); j++) {
                if (players[j]->isStillPlaying()) {
                    if (players[j]->getCurrentPosition() == i) {
                        line_1 += "(" + players[j]->getName() + ")";
                    }
                }
            }

            strings[i].push_back(printer.getColorChar(BrightRed) + line_0 + printer.getColorChar(White));
            strings[i].push_back(printer.getColorChar(BrightBlue) + line_1 + printer.getColorChar(White));
            strings[i].push_back(printer.getColorChar(BrightYellow) + line_2 + printer.getColorChar(White));
            strings[i].push_back(printer.getColorChar(BrightCyan) + line_3 + printer.getColorChar(White));
        }

        sbl::vector<std::string> lines;

        int line_index_start = 0;
        int string_indexing_starts = 0;

        while (string_indexing_starts < strings.size()) {
            lines.resize(lines.size() + 6);
            int limit = string_indexing_starts + max_cells;
            if (limit > strings.size()) {
                limit = strings.size();
            }
            for (int i = string_indexing_starts; i < limit; i++) {
                lines[line_index_start] += "/";
                for (int k = 0; k < cell_width; k++) {
                    lines[line_index_start] += "-";
                }
                lines[line_index_start] += "\\";
                for (int j = 0; j < strings[i].size(); j++) {
                    std::string ls = strings[i][j];
                    int jobb = true;
                    while (ls.length() < cell_width + 2 * printer.colorCharLength()) {
                        if (jobb) {
                            ls = ls + " ";
                        } else {
                            ls = " " + ls;
                        }
                        jobb = !jobb;
                    }
                    //ls += toStr(ls.length());
                    lines[line_index_start + j + 1] += "|" + ls + "|";
                }
                lines[line_index_start + 5] += "\\";
                for (int k = 0; k < cell_width; k++) {
                    lines[line_index_start + 5] += "-";
                }
                lines[line_index_start + 5] += "/";
            }
            string_indexing_starts += max_cells;
            line_index_start += 6;
        }

        for (int i = 0; i < lines.size(); i++) {
            printer.writeln(lines[i]);
        }
    }

}
