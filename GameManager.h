#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "HumanPlayer.h"
#include "ComputerPlayer.h"

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
        string emoji ;
       
       while (true)
       {
        
        cout << "Computer chose: " << computerMove ;
        if (computerMove==1)
        {
            emoji = "🪨";
        break;
        }
        else if (computerMove==2)
        {
        
            emoji = "📄";
        break; 
        }
         else if (computerMove==3)
        {
            emoji = "✂️";
        break;
        }
       }
            cout << emoji << endl ;
       

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
            human.incrementGamesWon();
        } else if (human.getScore() < computer.getScore()) {
            cout << "Computer wins the game with a score of " << computer.getScore() << "!" << endl;
            computer.incrementGamesWon();
        } else {
            cout << "The game is a tie!" << endl;
        }

        human.savePlayerData();
        computer.savePlayerData();
    }

    static void checkScoreByName(const string& playerName) {
        ifstream file(playerName + ".dat");
        if (file.is_open()) {
            int gamesWon;
            file >> gamesWon;
            file.close();
            cout << playerName << " has won " << gamesWon << " games." << endl;
        } else {
            cout << "No data found for player " << playerName << "." << endl;
        }
    }
};

#endif // GAMEMANAGER_H
