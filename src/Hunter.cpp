#include "Hunter.h"

Hunter::Hunter(std::string name): Character(name){
    std::cout << "Constrctor for Hunter class called" << std::endl;
}

void Hunter::attack(Character& target) {
    int damage = getAttackPower() - target.getDefence();
    if (damage < 1) {
        damage = 1;
    }
    target.takeDamage(damage);
}