#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include <iostream>
#include <limits>

class HumanPlayer : public Player {
public:
    HumanPlayer(const string& playerName) : Player(playerName) {}

    int makeMove() override {
        cout << getName() << ", enter your move (1 for Rock, 2 for Paper, 3 for Scissors): ";
        int move;
        while (true) {
            if (cin >> move && (move == 1 || move == 2 || move == 3)) {
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter 1, 2, or 3: ";
            }
        }
        return move;
    }
};

#endif // HUMANPLAYER_H
