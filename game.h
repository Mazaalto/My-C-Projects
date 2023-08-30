#include "dungeon.h"
#include "player.h"
#include <vector>
#ifndef GAME_H
#define GAME_H

class Game {
    private :
        Dungeon * dungeon;
        Player * player;
    public :
        bool gameOver;
        Game(Player *, Dungeon *);
        std::vector<std::string>getMovementActions();      
        void manageMovementActions();
        void printActions(std::vector<std::string>);
        void initRooms();
};
#endif