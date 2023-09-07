#include "player.h"

Player::Player(std::string _name, int _health, int _max, int _damage): Character(_name, _health, _max, _damage){}

void Player::drinkCaffeine(int amount) {
    health += amount;
    if (health < maxHealth) {
        health = maxHealth;
    }
}
void Player::enterRoom(room * newRoom){
    previous = current;
    current = newRoom;
}
void Player::runBack(){
    room * temp = current;
    previous = temp;   
}
void Player::pickUpItem(item item) {
  damage += item.damage;
  heal(item.health);
}