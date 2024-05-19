#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <iostream>
#include <ctime>

using namespace std;

class GameManager {
private:
    HumanPlayer human;
    ComputerPlayer computer;
    int rounds;

public:
    GameManager(const string& playerName) : human(playerName), rounds(5) {
        srand(time(0)); // Seed for random number generation
    }

    void playRound() {
        int humanMove = human.makeMove();
        int computerMove = computer.makeMove();

        cout << "Computer chose: " << computerMove << endl;

        if ((humanMove == 1 && computerMove == 3) ||
            (humanMove == 2 && computerMove == 1) ||
            (humanMove == 3 && computerMove == 2)) {
            cout << human.getName() << " wins this round!" << endl;
            human.increaseScore();
        } else if (humanMove == computerMove) {
            cout << "It's a tie this round!" << endl;
        } else {
            cout << "Computer wins this round!" << endl;
            computer.increaseScore();
        }

        rounds--;
    }

    void playGame() {
        cout << "Welcome to Rock-Paper-Scissors, " << human.getName() << "!" << endl;

        while (rounds > 0) {
            cout << "\nRound " << (5 - rounds) + 1 << " of 5:" << endl;
            playRound();
        }

        cout << "\nGame over!" << endl;
        if (human.getScore() > computer.getScore()) {
            cout << human.getName() << " wins the game with a score of " << human.getScore() << "!" << endl;
            cout << "Computer loses the game with a score of " << computer.getScore() << "." << endl;
        } else if (human.getScore() < computer.getScore()) {
            cout << "Computer wins the game with a score of " << computer.getScore() << "!" << endl;
            cout << human.getName() << " loses the game with a score of " << human.getScore() << "." << endl;
        } else {
            cout << "It's a tie game!" << endl;
            cout << human.getName() << " and Computer both have a score of " << human.getScore() << "." << endl;
        }
    }
};

#endif // GAMEMANAGER_H
