#ifndef HUNTER_H
#define HUNTER_H

#include "Character.h"
#include <iostream>

class Hunter : public Character
{
public:
    Hunter(std::string name);
    void attack(Character &target) override;
};

#endif // !HUNTER_H