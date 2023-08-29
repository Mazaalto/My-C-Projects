#include "character.h"

Character::Character(std::string _name, int _health, int _maxHealth, int _damage) {
    name = _name;
    health = _health;
    maxHealth = _maxHealth;
    damage = _damage;    
}
void Character::takeDamage(int amount) {
    health -= damage;
}
bool Character::alive(){
    return health > 0;
}
std::string Character::getName(){
    return name;
}
int Character::getDamage() {
    return damage;
}
int Character::getHealth() {
    return health;
}

    

