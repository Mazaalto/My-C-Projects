#include <iostream>
#include <vector>
#include <string>

using namespace std;
// std:: optional when using namespace std,
// eg. cout << "Hello, World!" << endl; is valid

class CharacterOfTheGame {
    private:
        int maxHealth;
        int currentHealth;

    public:
        std::string name;
        static std::string type;
        int damage;
        bool isAlive;
        // Constructor
        CharacterOfTheGame(std::string, int, int, int);
        // functions, methods
        void takeDamage(int);
        void healCharacter(int);
        static void changeTypeOfCharacter(std::string);
        int getHealth();
    // protected can be used in this class and all the subclasses
    // protected:
};
// inheritance
class PlayerCharacter: public CharacterOfTheGame {
    public:
        static std::string type;
        int level;
        int defence;
        void takeDamage(int);
        PlayerCharacter(std::string, int, int, int, int);
        // method overwriting / loading
};

PlayerCharacter::PlayerCharacter(std::string _name, int _maxHealth, int _currentHealth, int _damage, int _level)
: CharacterOfTheGame(_name, _maxHealth, _currentHealth, _damage) {
    level = _level;
    defence = 0;
}
// type is same for every instance, if changed changes same in every instance
std::string CharacterOfTheGame::type = "Non player character";

// new static type in Player class
std::string PlayerCharacter::type = "Player";

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
int CharacterOfTheGame::getHealth() {
    return currentHealth;
}
void PlayerCharacter::takeDamage(int amount) {
    int currentHealth = getHealth();
    currentHealth -= (amount - defence);
    if (currentHealth <= 0) {
        currentHealth = 0;
        isAlive = false;
    }
}
void CharacterOfTheGame::healCharacter(int amount) {
    int currentHealth = getHealth();
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
    
    
    /*
    CharacterOfTheGame character = CharacterOfTheGame("Matias", 100, 100, 10);
    PlayerCharacter player = PlayerCharacter("Player", 100, 100, 20, 1);

    character.takeDamage(10);
    player.takeDamage(5);
    std::cout << character.type << std::endl;
    std::cout << player.type << std::endl;
    */
}
