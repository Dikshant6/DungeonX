#include "Hunter.h"
#include <random>

Hunter::Hunter(std::string name) : Character(name)
{
}

Inventory &Hunter::getInventory()
{
    return inventory;
}
void Hunter::attack(Character &target)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> bonus(0, 5);

    int damage = getAttackPower();

    if (equippedWeapon != nullptr)
    {
        damage += equippedWeapon->getDamage();
    }

    int randomBonus = bonus(gen);
    damage += randomBonus;

    damage -= target.getDefence();

    if (damage < 1)
    {
        damage = 1;
    }

    std::cout << name << " attacks for "
              << damage << " damage! "
              << "(Random bonus: +" << randomBonus << ")\n";

    target.takeDamage(damage);
}

bool Hunter::equipWeapon(const std::string &weaponName)
{
    Weapon *weapon = inventory.findWeaponByName(weaponName);

    if (weapon == nullptr)
    {
        std::cout << "Weapon not found: " << weaponName << '\n';
        return false;
    }

    equippedWeapon = weapon;

    std::cout << "Equipped weapon: "
              << equippedWeapon->getName() << '\n';

    return true;
}