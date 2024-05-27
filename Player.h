#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Player {
protected:
    string  name;      // Name of the player
    int    score;      // Current game score of the player
    int gamesWon;      // Number of games won by the player

public:
    Player(const string& playerName) : name(playerName), score(0), gamesWon(0) {
        loadPlayerData();
    }

    virtual ~Player() {
        savePlayerData();
    }

    virtual int makeMove() = 0;
    void increaseScore() { score++; }
    int getScore() const { return score; }
    string getName() const { return name; }
    void incrementGamesWon() { gamesWon++; }
    int getGamesWon() const { return gamesWon; }

    virtual void savePlayerData() {
        ofstream file(name + ".dat");
        if (file.is_open()) {
            file << gamesWon << endl;
            file.close();
        }
    }

    virtual void loadPlayerData() {
        ifstream file(name + ".dat");
        if (file.is_open()) {
            file >> gamesWon;
            file.close();
        }
    }
};

#endif // PLAYER_H
