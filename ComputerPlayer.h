#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include <cstdlib>

class ComputerPlayer : public Player {
public:
    ComputerPlayer() : Player("Computer") {}

    int makeMove() override {
        return (rand() % 3) + 1; // Randomly choose between 1, 2, or 3
    }
};

#endif // COMPUTERPLAYER_H
