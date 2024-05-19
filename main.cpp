#include <iostream>
#include "GameManager.h"

using namespace std;

int main() {
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    GameManager game(playerName);
    game.playGame();

    return 0;
}
