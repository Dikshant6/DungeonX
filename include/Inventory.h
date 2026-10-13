#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <vector>
#include "Item.h"
#include <cstddef>
#include "Weapon.h"

class Inventory
{
private:
    std::vector<std::unique_ptr<Item>> items;

public:
    Inventory() = default;

    void displayAllItems() const;
    void displayAllWeapons() const;
    void displayAllPotions() const;
    void inventoryStats() const;
    void addItem(std::unique_ptr<Item> item);
    void removeItem(std::size_t index);
    Weapon *findWeaponByName(const std::string &name);
};

#endif // !INVENTORY_H