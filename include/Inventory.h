#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <vector>
#include "Item.h"
#include <cstddef>

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
};

#endif // !INVENTORY_H