#include "Character.h"
#include <iostream>

Character::Character(std::string name) : name(name), health(100), level(1), defence(10), attackPower(10), mana(200)
{
}

void Character::takeDamage(int damage)
{
    if (damage < 0)
    {
        return;
    }

    if (damage > health)
    {
        health = 0;
    }
    else
    {
        health -= damage;
    }
}

bool Character::isAlive() const
{
    return health > 0;
}

void Character::heal(int amount)
{
    if (health <= 0 || amount <= 0)
    {
        return;
    }

    health += amount;

    if (health > 100)
    {
        health = 100;
    }
}

int Character::getAttackPower() const
{
    return attackPower;
}

int Character::getDefence() const
{
    return defence;
}

void Character::displayStats() const
{
    std::cout << "================== Character Stats ==================" << std::endl;

    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attackPower << std::endl;
    std::cout << "Defence: " << defence << std::endl;
    std::cout << "Mana: " << mana << std::endl;

    std::cout << "=====================================================" << std::endl;
}