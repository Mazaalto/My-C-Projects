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
    // First enemies are Ikea furniture you have to build
    Character malm = Character("Malm", 30, 30, 10);
    Character Billy = Character("Billy", 60, 60, 20);
    Character enhet = Character("Enhet", 190, 190, 40);
    rooms[0][0].enemy_chores.push_back(enhet);
    rooms[1][2].enemy_chores.push_back(Billy);
    rooms[2][1].enemy_chores.push_back(malm);

    item hexKey;
    hexKey.health = 60;

    item electricalKey;
    electricalKey.name = "Troble maker perforator";
    electricalKey.damage = 25;
    rooms[1][1].items.push_back(hexKey);
    rooms[0][3].items.push_back(electricalKey);

}