#include "dungeon.h"

void Dungeon::setUpTheDungeon() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            room room;
            room.row = r;
            room.column = c;
            rooms[r][c] = room;
        } 
    }
}