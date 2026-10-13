#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"

class Goblin : public Character {
public:
    Goblin(std::string name);
    void attack(Character& target) override;
};

#endif