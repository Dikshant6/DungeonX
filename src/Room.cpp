
#include "Room.h"

#include <algorithm>
#include <iostream>
#include <utility>

Room::Room(const std::string &name, const std::string &description)
    : name(name),
      description(description) {}

const std::string &Room::getName() const
{
    return name;
}

const std::string &Room::getDescription() const
{
    return description;
}

void Room::addEnemy(std::unique_ptr<Character> enemy)
{
    if (enemy != nullptr)
    {
        enemies.push_back(std::move(enemy));
    }
}

std::vector<std::unique_ptr<Character>> &Room::getEnemies()
{
    return enemies;
}

bool Room::hasEnemies() const
{
    return std::any_of(
        enemies.begin(),
        enemies.end(),
        [](const std::unique_ptr<Character> &enemy)
        {
            return enemy != nullptr && enemy->isAlive();
        });
}

void Room::displayInfo() const
{
    std::cout << "\n========================================\n";
    std::cout << "  ROOM: " << name << '\n';
    std::cout << "========================================\n";
    std::cout << description << '\n';

    if (hasEnemies())
    {
        std::cout << "\nHostile entities detected!\n";

        for (const auto &enemy : enemies)
        {
            if (enemy && enemy->isAlive())
            {
                std::cout << "  - " << enemy->getName()
                          << " | HP: " << enemy->getHealth()
                          << '\n';
            }
        }
    }
    else
    {
        std::cout << "\nRoom cleared. No hostile entities remain.\n";
    }

    std::cout << "========================================\n";
}
