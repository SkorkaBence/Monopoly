#include "Monopoly/Printer/Printer.h"
#include "Monopoly/Fields/Field.h"
#include "Monopoly/Fields/Property.h"
#include "Monopoly/Fields/Service.h"
#include "Monopoly/Fields/Luck.h"
#include "Monopoly/Fields/Chance.h"
#include <iostream>
#include <string>
#include <sstream>

namespace Monopoly {

    Printer::Printer() {

    }

    Printer::~Printer() {
        resetColor();
    }

    void Printer::changeColor(ConsoleColors color) {
        if (color == 100) {
            // invalid
        } else if (color >= 100) {
            // bright
            int cm = color - 100;
            std::string str = "%c[1;" + toStr(cm) + "m";
            const char * c = str.c_str();
            printf(c, 27);
        } else {
            // normal
            int cm = color;
            std::string str = "%c[0;" + toStr(cm) + "m";
            const char * c = str.c_str();
            printf(c, 27);
        }
    }

    void Printer::resetColor() {
        changeColor(White);
    }

    void Printer::write(std::string str) {
        std::cout << str;
    }

    void Printer::writeln(std::string str) {
        std::cout << str << std::endl;
    }

    std::string Printer::getColorChar(ConsoleColors color) {
        if (!enableColors) {
            return "";
        }
        char buffer[50];
        if (color == 100) {
            // invalid
        } else if (color >= 100) {
            // bright
            int cm = color - 100;
            std::string str = "%c[1;" + toStr(cm) + "m";
            const char * c = str.c_str();
            sprintf(buffer, c, 27);
        } else {
            // normal
            int cm = color;
            std::string str = "%c[0;" + toStr(cm) + "m";
            const char * c = str.c_str();
            sprintf(buffer, c, 27);
        }
        std::string str(buffer);
        return buffer;
    }

    unsigned int Printer::colorCharLength() {
        if (enableColors) {
            return 7;
        } else {
            return 0;
        }
    }

    void Printer::setColorEnabled(bool status) {
        enableColors = status;
    }

    void Printer::printGameState(const Game& game) {
        writeln("Tick " + toStr(game.tick) + ":");

        int max_cells = 8;
        int cell_width = 20;

        sbl::vector<sbl::vector<std::string> > strings;
        strings.resize(game.fields.size());

        for (unsigned int i = 0; i < game.fields.size(); i++) {

            std::string line_0 = game.fields[i]->getShortName();
            std::string line_1 = "";
            std::string line_2 = "";
            std::string line_3 = toStr(game.fields[i]->moneyChange());

            if(Property* v = dynamic_cast<Property*>(game.fields[i])) {
                line_3 = "-" + toStr(v->getUpgradePrice()) + "/" + toStr(v->moneyChange());
                if (v->isSold()) {
                    line_2 = v->getOwner()->getName();
                }
            }

            line_1 = "";
            for (unsigned int j = 0; j < game.players.size(); j++) {
                if (game.players[j]->isStillPlaying()) {
                    if (game.players[j]->getCurrentPosition() == i) {
                        line_1 += "(" + game.players[j]->getShortName() + ")";
                    }
                }
            }

            strings[i].push_back(getColorChar(BrightRed) + line_0 + getColorChar(White));
            strings[i].push_back(getColorChar(BrightBlue) + line_1 + getColorChar(White));
            strings[i].push_back(getColorChar(BrightYellow) + line_2 + getColorChar(White));
            strings[i].push_back(getColorChar(BrightCyan) + line_3 + getColorChar(White));
        }

        sbl::vector<std::string> lines;

        unsigned int line_index_start = 0;
        unsigned int string_indexing_starts = 0;

        while (string_indexing_starts < strings.size()) {
            lines.resize(lines.size() + 6);
            unsigned int limit = string_indexing_starts + max_cells;
            if (limit > strings.size()) {
                limit = strings.size();
            }
            for (unsigned int i = string_indexing_starts; i < limit; i++) {
                lines[line_index_start] += "/";
                for (int k = 0; k < cell_width; k++) {
                    lines[line_index_start] += "-";
                }
                lines[line_index_start] += "\\";
                for (unsigned int j = 0; j < strings[i].size(); j++) {
                    std::string ls = strings[i][j];
                    bool jobb = true;
                    while (ls.length() < cell_width + 2 * colorCharLength()) {
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

        for (unsigned int i = 0; i < lines.size(); i++) {
            writeln(lines[i]);
        }
    }

}
