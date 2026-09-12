#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{
    //data members
    protected:
        std::string name;
        int health;
        int level;
        int defence;
        int attackPower;
        int mana;
        
        // Functions
    public:
        Character(std::string name);
        virtual ~Character() = default;
        virtual void attack(Character& target) = 0;
        void takeDamage(int damage);
        bool isAlive() const;
        void heal(int amount);
        void displayStats() const;
        int getDefence() const;
        int getAttackPower() const;
};

#endif