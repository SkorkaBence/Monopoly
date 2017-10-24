#include "Monopoly/Game.h"
#include "Monopoly/MonopolyException.h"
#include "Monopoly/Randomizer/OneDice.h"
#include "Monopoly/Fields/Field.h"
#include "Monopoly/Fields/Property.h"
#include "Monopoly/Fields/Service.h"
#include "Monopoly/Fields/Luck.h"
#include "Monopoly/Player/Player.h"
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
            random = new OneDice();
        } else {
            throw MonopolyException("Invalid dice type");
        }

        int starting_money;
        file >> starting_money;

        int fields_length;
        file >> fields_length;

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

        int start_money;
        file >> start_money;

        int player_number;
        file >> player_number;

        players.resize(player_number);

        for (int i = 0; i < player_number; i++) {
            std::string name;
            file >> name;
            std::string type;
            file >> type;

            Player* player = new Player(starting_money);

            if (type == "greedy") {

            } else if (type == "careful") {

            } else if (type == "tactician") {

            } else if (type == "human") {

            } else {
                throw MonopolyException("Invalid AI type");
            }
        }
    }

}
