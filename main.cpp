#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
#include "GameManager.h"

using namespace std;

int main() {
    string playerName;
    int choice;

    while (true) {
        cout << "1. Play Game\n2. Check Score by Player Name\n3. Sign Out\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter your name: ";
            cin >> playerName;

            GameManager game(playerName);
            game.playGame();
        } else if (choice == 2) {
            cout << "Enter player name to check score: ";
            cin >> playerName;

            GameManager::checkScoreByName(playerName);
        } else if (choice == 3) {
            cout << "Signing out. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }
    return 0;
}
