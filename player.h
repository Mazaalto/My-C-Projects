#include "character.h"
#include "room.cpp"

class Player: public Character {
    room * current;
    room * previous;
    Player(std::string, int, int);
    void drinkCaffeine(int);
    void enterRoom(room *);
    void runBack();

};