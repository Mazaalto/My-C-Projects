#include <vector>
#include "character.h"
#include "item.cpp"
#ifndef ROOM_CPP
#define ROOM_CPP
// if the roof is not defined, whe define room.cpp

struct room {
    int row;
    int column;
    std::vector<Character> enemy_chores;
    std::vector<item> items;
};
#endif