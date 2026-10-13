#include "Goblin.h"
#include <iostream>
#include <random>

Goblin::Goblin(std::string name) : Character(name)
{
    health = 50;
    maxHealth = 50;
    attackPower = 8;
    defence = 3;
}

void Goblin::attack(Character &target)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> bonus(0, 3);

    int damage = getAttackPower() + bonus(gen);
    damage -= target.getDefence();

    if (damage < 1)
    {
        damage = 1;
    }
    std::cout << name << " attacks for "
              << damage << " damage!\n";

    target.takeDamage(damage);
}