#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include <iostream>

class Weapon : public Item{
    private:
        int damage;
    
    public:
        Weapon(std::string name, int damage);
        void use() override;
        void displayInfo() const override;
        int getDamage() const;
};

#endif // !WEAPON_H