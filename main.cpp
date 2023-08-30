#include <iostream>
#include <vector>
#include <string>
#include "game.h"

using namespace std;
// std:: optional when using namespace std,
// eg. cout << "Hello, World!" << endl; is valid

int main() {
    cout << "Welcome to Diaper's Gate" << endl;
    Player player = Player("Dad", 100, 100, 10);
    Dungeon dungeon;
    Game game = Game(&player, &dungeon);
    while (!game.gameOver) {
        // Room sequence
        game.initRooms();
    }
    game.manageMovementActions();
}
