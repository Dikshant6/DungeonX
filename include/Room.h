#ifndef ROOM_H
#define ROOM_H

#include <memory>
#include <string>
#include <vector>

#include "Character.h"

class Room
{
private:
    std::string name;
    std::string description;
    std::vector<std::unique_ptr<Character>> enemies;

public:
    Room(const std::string &name, const std::string &description);

    const std::string &getName() const;
    const std::string &getDescription() const;

    void addEnemy(std::unique_ptr<Character> enemy);

    std::vector<std::unique_ptr<Character>> &getEnemies();

    bool hasEnemies() const;
    void displayInfo() const;
};

#endif