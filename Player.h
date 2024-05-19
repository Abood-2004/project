#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
protected:
    string name;
    int score;

public:
    Player(const string& playerName) : name(playerName), score(0) {}
    virtual ~Player() {}

    virtual int makeMove() = 0;
    void increaseScore() { score++; }
    int getScore() const { return score; }
    string getName() const { return name; }
};

#endif // PLAYER_H
