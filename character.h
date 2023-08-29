#include <string>
#ifndef CHARACTER_H
#define CHARACTER_H


class Character {
    private:
        std::string name;
        int health;
        int maxHealth;
        int damage;

    public:  
        Character(std::string, int, int, int);
        void takeDamage(int);
        bool alive();
        std::string getName();
        int getHealth();
        int getDamage();
};
#endif