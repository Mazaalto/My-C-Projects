#include "game.h"
#include <iostream>

void Game::initRooms() {
    manageMovementActions();
}
Game::Game(Player * _player, Dungeon * _dungeon) {
    player = _player;
    dungeon = _dungeon;
    gameOver = false;
    dungeon->setUpTheDungeon();
    player->current = &dungeon->rooms[dungeon->rows-1][dungeon->columns-1];
}
std::vector<std::string> Game::getMovementActions(){
    std::vector<std::string> listOfActions;
    room * currentRoom = player->current;
    if (currentRoom->column > 0) {
        listOfActions.push_back("Move left");
    }
    if (currentRoom->row > 0) {
        listOfActions.push_back("Move up");
    }
    if (currentRoom->column < (dungeon->columns) - 1) {
        listOfActions.push_back("Move right");
    }
    if (currentRoom->row <  (dungeon->rows - 1)) {
        listOfActions.push_back("Move down");
    }
    return listOfActions;
}
void Game::manageMovementActions() {
    // give choices to player
    std::cout << "Where to go?\n";
    std::vector<std::string> actions = getMovementActions();
    printActions(actions);
    int input;
    std::cin >> input;
    std::string chosen = actions[input - 1];

    int horizontalMove = 0;
    int verticalMove = 0;
    // Movement changes
    if (chosen == "Move left") {
        horizontalMove = -1;
    }
    else if (chosen == "Move up") {
        verticalMove = -1;
    }
    else if (chosen == "Move right") {
        horizontalMove = 1;
    }
    else if (chosen == "<Move down>") {
        verticalMove = 1;
    }
    room * newRoom = &dungeon->rooms[player->current->row + verticalMove][player->current->column + horizontalMove];
    player->enterRoom(newRoom);

    std::cout << "Now you are in room " << newRoom->row << " " << newRoom->column << std::endl;
}
void Game::printActions(std::vector<std::string> actions){
    for (int i = 0; i < actions.size(); i++) {
        std::cout << i + 1 << ". "<< actions[i] << std::endl;    
    }    
}