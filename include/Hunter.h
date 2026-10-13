#ifndef HUNTER_H
#define HUNTER_H

#include "Character.h"
#include <iostream>
#include "Inventory.h"
#include "Weapon.h"

class Hunter : public Character
{
private:
    Inventory inventory;
    Weapon *equippedWeapon = nullptr;

public:
    Inventory &getInventory();
    Hunter(std::string name);
    void attack(Character &target) override;
    bool equipWeapon(const std::string &weaponName);
};

#endif // !HUNTER_H