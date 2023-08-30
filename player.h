#include "character.h"
#include "room.cpp"
#ifndef PLAYER_H
#define PLAYER_H

class Player: public Character {
    private:
        room * previous;    
    public:
        room * current;
        Player(std::string, int, int, int);
        void drinkCaffeine(int);
        void enterRoom(room *);
        void runBack();
};
#endif