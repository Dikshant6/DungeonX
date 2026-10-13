#include <iostream>
#include <memory>

#include "Inventory.h"
#include "Weapon.h"
#include "Potion.h"

int main()
{
    Inventory inventory;

    std::cout << "\n--- Adding Items ---\n";

    inventory.addItem(
        std::make_unique<Weapon>("Iron Sword", 15));

    inventory.addItem(
        std::make_unique<Potion>("Health Potion", "Healing"));

    inventory.addItem(
        std::make_unique<Weapon>("Shadow Dagger", 25));

    std::cout << "\n--- All Items ---\n";
    inventory.displayAllItems();

    std::cout << "\n--- Weapons ---\n";
    inventory.displayAllWeapons();

    std::cout << "\n--- Potions ---\n";
    inventory.displayAllPotions();

    std::cout << "\n--- Inventory Stats ---\n";
    inventory.inventoryStats();

    std::cout << "\n--- Removing Item at Index 1 ---\n";
    inventory.removeItem(1);

    inventory.inventoryStats();

    std::cout << "\n--- Testing Invalid Index ---\n";
    inventory.removeItem(99);

    return 0;
}