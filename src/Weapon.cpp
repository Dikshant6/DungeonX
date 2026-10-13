#include "Weapon.h"

Weapon::Weapon(std::string name, int damage)
    : Item(name), damage(damage) {}

int Weapon::getDamage() const
{
    return damage;
}

void Weapon::displayInfo() const
{
    std::cout << "========== Weapon ==========" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "============================" << std::endl;
}

void Weapon::use()
{
    std::cout << name << " is ready to be equipped.\n";
}