#include "Potion.h"

Potion::Potion(std::string name, std::string effect) : Item(name), effect(effect) {}

void Potion::displayInfo() const
{
    std::cout << "========== Potion ==========" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Effect: " << effect << std::endl;
    std::cout << "============================" << std::endl;
}
void Potion::use()
{
    std::cout << name << " is ready to be used.\n";
}

std::string Potion::getEffect() const
{
    return effect;
}