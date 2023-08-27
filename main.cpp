#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CharacterOfTheGame {
    public:
        std::string name;
        int maxHealth;
        int currentHealth;
        int damage;
        bool isAlive;
        // Constructor
        CharacterOfTheGame(std::string, int, int, int);
        // functions, methods
        void takeDamage(int);
        void healCharacter(int);
};

CharacterOfTheGame::CharacterOfTheGame(std::string _name, int _maxHealth, int _currentHealth, int _damage) {
    name = _name;
    maxHealth = _maxHealth;
    currentHealth = _currentHealth;
    damage = _damage;
    isAlive = true;
}

void CharacterOfTheGame::takeDamage(int amount) {
    currentHealth -= amount;
    if (currentHealth <= 0) {
        currentHealth = 0;
        isAlive = false;
    }
}
void CharacterOfTheGame::healCharacter(int amount) {
    currentHealth += amount;
    if (currentHealth >= maxHealth) {
        currentHealth = maxHealth;
    }
}

int main() {
    CharacterOfTheGame character = CharacterOfTheGame("Matias", 100, 100, 10);
    character.takeDamage(10);

    std::cout << character.currentHealth << std::endl;
    std::cout << character.isAlive << std::endl;

    character.healCharacter(10);

    std::cout << character.currentHealth << std::endl;
    std::cout << character.isAlive << std::endl;

}
