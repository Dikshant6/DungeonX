#include "Inventory.h"
#include "Weapon.h"
#include "Potion.h"

void Inventory::displayAllItems() const
{
    std::cout << "\n========== INVENTORY ==========\n";

    if (items.empty())
    {
        std::cout << "Inventory is empty.\n";
        std::cout << "===============================\n";
        return;
    }

    for (const auto &item : items)
    {
        item->displayInfo();
    }

    std::cout << "===============================\n";
}

void Inventory::displayAllWeapons() const
{
    std::cout << "\n========== WEAPONS ==========\n";

    bool found = false;

    for (const auto &item : items)
    {
        if (dynamic_cast<Weapon *>(item.get()))
        {
            item->displayInfo();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No weapons in inventory.\n";
    }

    std::cout << "=============================\n";
}

void Inventory::displayAllPotions() const
{
    std::cout << "\n========== POTIONS ==========\n";

    bool found = false;

    for (const auto &item : items)
    {
        if (dynamic_cast<Potion *>(item.get()))
        {
            item->displayInfo();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No potions in inventory.\n";
    }

    std::cout << "=============================\n";
}

void Inventory::inventoryStats() const
{
    int weaponCount = 0;
    int potionCount = 0;

    for (const auto &item : items)
    {
        if (dynamic_cast<Weapon *>(item.get()))
        {
            weaponCount++;
        }
        else if (dynamic_cast<Potion *>(item.get()))
        {
            potionCount++;
        }
    }

    std::cout << "\n========== INVENTORY STATS ==========\n";
    std::cout << "Total Items : " << items.size() << '\n';
    std::cout << "Weapons     : " << weaponCount << '\n';
    std::cout << "Potions     : " << potionCount << '\n';
    std::cout << "=====================================\n";
}

void Inventory::addItem(std::unique_ptr<Item> item)
{
    if (!item)
    {
        std::cout << "Error: Cannot add an empty item!\n";
        return;
    }

    items.push_back(std::move(item));

    std::cout << "Item added to inventory successfully!\n";
}

void Inventory::removeItem(std::size_t index)
{
    if (index >= items.size())
    {
        std::cout << "Error: Invalid item index!\n";
        return;
    }

    std::cout << "Removed item: "
              << items[index]->getName() << '\n';

    items.erase(items.begin() + index);
}
Weapon *Inventory::findWeaponByName(const std::string &name)
{
    for (const auto &item : items)
    {
        Weapon *weapon = dynamic_cast<Weapon *>(item.get());

        if (weapon && weapon->getName() == name)
        {
            return weapon;
        }
    }

    return nullptr;
}