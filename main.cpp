#include <iostream>
#include <vector>
#include <string>

using namespace std;
// std:: optional when using namespace std,
// eg. cout << "Hello, World!" << endl; is valid

class CharacterOfTheGame {
    public:
        std::string name;
        static std::string type;
        int maxHealth;
        int currentHealth;
        int damage;
        bool isAlive;
        // Constructor
        CharacterOfTheGame(std::string, int, int, int);
        // functions, methods
        void takeDamage(int);
        void healCharacter(int);
        static void changeTypeOfCharacter(std::string);
};
// inheritance
class PlayerCharacter: public CharacterOfTheGame {
    public:
        int level;
        PlayerCharacter(std::string, int, int, int, int);

};

PlayerCharacter::PlayerCharacter(std::string _name, int _maxHealth, int _currentHealth, int _damage, int _level)
: CharacterOfTheGame(_name, _maxHealth, _currentHealth, _damage) {
    level = _level;
}
// type is same for every instance, if changed changes same in every instance
std::string CharacterOfTheGame::type = "Non player character";


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
// static functions cannot change any values instance related
void CharacterOfTheGame::changeTypeOfCharacter(std::string newType) {
    type = newType;
    // this gives error: currentHealth = 0;

}
// Character 1 attacks Character 2, with the power of that character, by using pointers
void attackCharacter (CharacterOfTheGame *characterPointer1, CharacterOfTheGame *characterPointer2) {
    int damageTaken = characterPointer1 -> damage;
    characterPointer2-> takeDamage(damageTaken);
}



int main() {
    CharacterOfTheGame character = CharacterOfTheGame("Matias", 100, 100, 10);
    CharacterOfTheGame character2 = CharacterOfTheGame("Enzio", 100, 100, 20);
    attackCharacter(&character2, &character);

    std::cout << character.currentHealth << std::endl;
    std::cout << character.isAlive << std::endl;

}
