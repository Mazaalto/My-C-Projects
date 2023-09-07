#include "game.h"
#include <iostream>

void Game::initRooms() {
    room * room = player->current;
  if (room->row == 0 && room->column == 0 && room->enemy_chores.empty()) {
    std::cout << "Congratulations, you have reached the exit and are free of the dungeon! Farwell " << player->getName() << "!\n";
    gameOver = true;
    return;
  }
  if (!room->enemy_chores.empty()) {
    manageEnemyActions();
  } else if (!room->items.empty()) {
    handleItemActions();
  } else {
    manageMovementActions();
  }
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
void Game::manageEnemyActions() {
    // give choices to player
    std::cout << "There is a house chore " << player->current->enemy_chores[0].getName() << " in this room! What would you like to do?\n";
    std::vector<std::string> actions;
    actions.push_back("Engage the chore like an enemy in a dungeon");
    actions.push_back("Retreat like a loser");
    printActions(actions);
    int input;
    std::cin >> input;
    if (input == 1) {
        buildFurniture();
    } else {
        player->runBack();
    }
}
void Game::buildFurniture() {
    // pointer for referencing specific chore, changes are reflected in the enemy chore
    Character *chore = &player->current->enemy_chores[0];
    while (true) {
        chore->takeDamage(player->getDamage());
        std::cout << "You managed to do a bit of the chore" << chore->getName() << ", doing "<< player->getDamage() << " parts.\n";
        if (!chore->alive()) {
            std::cout << "You are a warrior dad, you managed to do " << chore->getName() << "!\n"; 
            // currently only one chore in v 1.0
            player->current->enemy_chores.clear();
            return;
        }
        player->takeDamage(chore->getDamage());
        std::cout << "You take " << chore->getDamage()<< " stress damage. You still have "<< player->getHealth() << " energy.\n";
        if (!player->alive()) {
            gameOver = true;
            std::cout << "You are defeated by the chores, take care of afterlife then! " << chore->getName() << "!\n"; 
            // currently only one chore in v 1.0
            player->current->enemy_chores.clear();
            return;
        }
        std::cout << "Do you want to keep fighting or run away from your chore?\n ";
        std::vector<std::string> actions;
        actions.push_back("Never give up");
        actions.push_back("Hide in a closet");
        printActions(actions);

        int input;
        std::cin >> input;
        if (input == 1) {
            player->runBack();
            return;
        }  
    }
}
    void Game::handleItemActions() {
        item item = player->current->items[0];
        std::cout << "You find a " << item.name << " in this room! What would you like to do?\n";
        std::vector<std::string> actions;
        actions.push_back("Pick up item");
        actions.push_back("Ignore item");
        printActions(actions);
        int input;
        std::cin >> input;
        if (input == 1) {
            player->pickUpItem(item);
            std::cout << "You picked up a " << item.name << ". Your mental energy is now " << player->getHealth() << " and your damage is now " << player->getDamage() << ".\n";
            player->current->items.clear();
        } else {
            manageMovementActions();
        }
    }
