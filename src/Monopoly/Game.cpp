#include "Monopoly/Game.h"
#include "Monopoly/MonopolyException.h"
#include "Monopoly/Randomizer/OneDice.h"
#include "Monopoly/Randomizer/PreDefined.h"
#include "Monopoly/Fields/Field.h"
#include "Monopoly/Fields/Property.h"
#include "Monopoly/Fields/Service.h"
#include "Monopoly/Fields/Luck.h"
#include "Monopoly/Fields/Chance.h"
#include "Monopoly/Player/Player.h"
#include "Monopoly/Player/AI/Greedy.h"
#include "Monopoly/Player/AI/Careful.h"
#include "Monopoly/Player/AI/Tactician.h"
#include "Monopoly/Printer/Printer.h"
#include <fstream>

namespace Monopoly {
    Game::Game(std::string filename) {
        loadGame(filename);
    }

    Game::~Game() {
        delete random;
        for (unsigned int i = 0; i < fields.size(); i++) {
            delete fields[i];
        }
        for (unsigned int i = 0; i < players.size(); i++) {
            delete players[i];
        }
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
            } else if (type == "chance") {
                field = new Chance;
            } else {
                throw MonopolyException("Invalid field type: (" + toStr(i) + ") " + type);
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
        unsigned int newpos = currentPlayer->getCurrentPosition() + diceRoll;
        while (newpos >= fields.size()) {
            currentPlayer->finishedRound();
            newpos -= fields.size();
        }

        currentPlayer->setCurrentPosition(newpos);
        fields[newpos]->steppedOn(currentPlayer);

        if (!currentPlayer->isStillPlaying()) {
            // kiesett a jatekbol
            for (unsigned int i = 0; i < fields.size(); i++) {
                fields[i]->reset(currentPlayer);
            }
        }

        int cpi = nextPlayer;

        int playercount = 0;
        for (unsigned int i = 0; i < players.size(); i++) {
            if (players[i]->isStillPlaying()) {
                playercount++;
            }
        }
        if (playercount < 2) {
            return false;
        }

        do {
            nextPlayer = (nextPlayer + 1) % players.size();
            if (cpi == nextPlayer) {
                return false;
            }
        } while (!players[nextPlayer]->isStillPlaying());

        return true;
    }

}
