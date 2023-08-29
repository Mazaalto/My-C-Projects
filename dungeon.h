#include "room.cpp"
#ifndef DUNGEON_H
#define DUNGEON_H

class Dungeon {
    public:
        int rows = 3;
        int columns = 3;
        room rooms[3][3];

        void setUpTheDungeon();

};

#endif