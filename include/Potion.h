#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include <iostream>
#include <string>

class Potion : public Item{
    private:
        std::string effect;
    
    public:
        Potion(std::string name, std::string effect);
        void use() override;
        void displayInfo() const override;
        std::string getEffect() const;
};

#endif // !POTION_H