#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <string>

#include "Hunter.h"
#include "Weapon.h"
#include "Potion.h"
#include "Goblin.h"
#include "Inventory.h"

namespace UI
{
    constexpr int WIDTH = 62;

    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string PURPLE = "\033[38;5;141m";
    const std::string CYAN = "\033[38;5;117m";
    const std::string GREY = "\033[38;5;245m";
    const std::string WHITE = "\033[38;5;255m";
    const std::string RED = "\033[38;5;203m";
    const std::string GREEN = "\033[38;5;120m";
    const std::string GOLD = "\033[38;5;221m";

    void clearScreen()
    {
        std::cout << "\033[2J\033[H";
    }

    void line(char symbol = '-')
    {
        std::cout << PURPLE << "  +" << std::string(WIDTH, symbol)
                  << "+" << RESET << '\n';
    }

    void row(const std::string &text, const std::string &color = WHITE)
    {
        std::string visible = text;
        if (visible.size() > WIDTH)
        {
            visible = visible.substr(0, WIDTH);
        }

        std::cout << PURPLE << "  |" << RESET
                  << color << std::left << std::setw(WIDTH) << visible
                  << RESET << PURPLE << "|" << RESET << '\n';
    }

    void centered(const std::string &text, const std::string &color = WHITE)
    {
        const std::string visible = text.substr(0, WIDTH);
        const int left = (WIDTH - static_cast<int>(visible.size())) / 2;
        const int right = WIDTH - static_cast<int>(visible.size()) - left;

        std::cout << PURPLE << "  |" << RESET
                  << std::string(left, ' ')
                  << color << visible << RESET
                  << std::string(right, ' ')
                  << PURPLE << "|" << RESET << '\n';
    }

    void showBanner()
    {
        clearScreen();
        std::cout << '\n';
        line('=');
        centered("D U N G E O N X", BOLD + PURPLE);
        centered("H U N T E R   S Y S T E M", CYAN);
        line('=');
        centered("AWAKENING PROTOCOL  //  SYSTEM ONLINE", GREY);
        line('=');
        std::cout << '\n';
    }

    void showMenu(const std::string &name)
    {
        clearScreen();
        std::cout << '\n';
        line('=');
        centered("HUNTER COMMAND CENTER", BOLD + PURPLE);
        line();
        row("  HUNTER   //   " + name, CYAN);
        row("  STATUS   //   ACTIVE", GREEN);
        line();
        row("  [ 1 ]     Hunter Profile");
        row("");
        row("  [ 2 ]     Inventory");
        row("");
        row("  [ 3 ]     Enter the Dungeon", GOLD);
        row("");
        row("  [ 4 ]     Terminate Session", RED);
        line('=');
        row("  SYSTEM   >   Awaiting command...", PURPLE);
        line('=');
        std::cout << "\n  " << CYAN << "COMMAND  >> " << RESET;
    }

    void healthBar(const std::string &name, int current, int maximum,
                   const std::string &color)
    {
        constexpr int BAR_WIDTH = 26;
        if (maximum <= 0)
            return;

        current = std::clamp(current, 0, maximum);
        const int filled = current * BAR_WIDTH / maximum;

        std::cout << "  " << std::left << std::setw(20) << name << ' '
                  << color << '[';
        for (int i = 0; i < BAR_WIDTH; ++i)
        {
            std::cout << (i < filled ? "█" : GREY + std::string("░") + color);
        }
        std::cout << ']' << RESET << ' '
                  << std::right << std::setw(3) << current << '/' << maximum
                  << RESET << '\n';
    }

    void showBattle(const Hunter &player, const Goblin &goblin)
    {
        clearScreen();
        std::cout << '\n';
        line('=');
        centered("DUNGEON ENCOUNTER", BOLD + PURPLE);
        centered("FLOOR 01   //   HOSTILE ENTITY DETECTED", GREY);
        line('=');
        row("  HUNTER STATUS", CYAN);
        healthBar(player.getName(), player.getHealth(), player.getMaxHealth(), CYAN);
        std::cout << '\n';
        row("  TARGET STATUS", RED);
        healthBar(goblin.getName(), goblin.getHealth(), goblin.getMaxHealth(), RED);
        line('=');
        std::cout << '\n';
    }

    void showVictory(const std::string &enemyName)
    {
        clearScreen();
        std::cout << '\n';
        line('=');
        centered("DUNGEON CLEARED", BOLD + GREEN);
        line('=');
        std::cout << '\n';
        centered("        /\\", PURPLE);
        centered("       /  \\ ", PURPLE);
        centered("      /____\\", PURPLE);
        std::cout << '\n';
        centered("VICTORY", BOLD + GOLD);
        centered(enemyName + " has been defeated.", WHITE);
        centered("HOSTILE ENTITY ELIMINATED", GREEN);
        line('=');
        std::cout << '\n';
    }

    void showDefeat(const std::string &hunterName)
    {
        clearScreen();
        std::cout << '\n';
        line('=');
        centered("HUNTER DOWN", BOLD + RED);
        line('=');
        std::cout << '\n';
        centered("MISSION FAILED", RED);
        centered(hunterName + " has fallen in battle.", WHITE);
        centered("VITAL SIGNS LOST", RED);
        std::cout << '\n';
        centered("THE DUNGEON CLAIMS ANOTHER HUNTER", GREY);
        line('=');
        std::cout << '\n';
    }

    void showLoot(const std::string &itemName)
    {
        clearScreen();
        std::cout << '\n';
        line('=');
        centered("SYSTEM REWARD ACQUIRED", BOLD + GOLD);
        centered(itemName, GREEN);
        line();
    }
}

void generateLoot(Inventory &inventory)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> chance(1, 100);
    std::uniform_int_distribution<int> lootType(1, 2);

    std::cout << "\n";
    if (chance(gen) > 75)
    {
        UI::clearScreen();
        UI::line('=');
        UI::centered("DROP SCAN COMPLETE", UI::BOLD + UI::GREY);
        UI::line('=');
        UI::centered("No loot detected.", UI::GREY);
        UI::line('=');
        return;
    }

    if (lootType(gen) == 1)
    {
        inventory.addItem(std::make_unique<Potion>("Health Potion", "Healing"));
        UI::showLoot("Health Potion");
    }
    else
    {
        inventory.addItem(std::make_unique<Weapon>("Goblin Blade", 8));
        UI::showLoot("Goblin Blade  //  +8 weapon damage");
    }
}

bool readChoice(int &choice)
{
    if (std::cin >> choice)
        return true;

    std::cin.clear();
    return false;
}

void waitForEnter()
{
    std::cout << "\n  " << UI::GREY << "Press ENTER to continue..." << UI::RESET;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main()
{
    std::string name;
    UI::showBanner();

    std::cout << "  Enter Hunter name: ";
    std::getline(std::cin, name);
    if (name.find_first_not_of(" \t\n\r") == std::string::npos)
    {
        name = "Unknown Hunter";
    }

    Hunter player(name);
    auto &inventory = player.getInventory();
    inventory.addItem(std::make_unique<Weapon>("Iron Sword", 15));
    inventory.addItem(std::make_unique<Potion>("Health Potion", "Healing"));
    inventory.addItem(std::make_unique<Potion>("Small Health Potion", "Healing"));

    std::cout << '\n';
    UI::line('=');
    UI::row("  IDENTITY VERIFIED", UI::CYAN);
    UI::row("  Welcome, Hunter " + name + ".");
    UI::row("  Your journey begins now.", UI::GREY);
    UI::line('=');
    std::cout << "\n  Press ENTER to access the command center...";
    std::cin.get();

    int choice = 0;
    while (true)
    {
        UI::showMenu(name);
        if (!readChoice(choice))
        {
            std::cout << '\n'
                      << UI::RED << "  Invalid command. Use 1-4."
                      << UI::RESET << '\n';
            waitForEnter();
            continue;
        }

        switch (choice)
        {
        case 1:
            std::cout << '\n';
            player.displayStats();
            waitForEnter();
            break;

        case 2:
        {
            int inventoryChoice = 0;
            std::cout << "\n";
            UI::line('=');
            UI::centered("INVENTORY", UI::BOLD + UI::PURPLE);
            UI::line();
            UI::row("  [ 1 ]   All Items");
            UI::row("");
            UI::row("  [ 2 ]   Weapons");
            UI::row("");
            UI::row("  [ 3 ]   Potions");
            UI::row("");
            UI::row("  [ 4 ]   Inventory Stats");
            UI::row("");
            UI::row("  [ 5 ]   Equip Iron Sword", UI::GOLD);
            UI::row("");
            UI::row("  [ 6 ]   Back");
            UI::line('=');
            std::cout << "\n  " << UI::CYAN << "INVENTORY >> " << UI::RESET;

            if (!readChoice(inventoryChoice))
            {
                std::cout << UI::RED << "Invalid input.\n"
                          << UI::RESET;
                waitForEnter();
                break;
            }

            switch (inventoryChoice)
            {
            case 1:
                inventory.displayAllItems();
                break;
            case 2:
                inventory.displayAllWeapons();
                break;
            case 3:
                inventory.displayAllPotions();
                break;
            case 4:
                inventory.inventoryStats();
                break;
            case 5:
                player.equipWeapon("Iron Sword");
                break;
            case 6:
                break;
            default:
                std::cout << UI::RED << "Invalid choice!\n"
                          << UI::RESET;
            }
            if (inventoryChoice != 6)
                waitForEnter();
            break;
        }

        case 3:
        {
            Goblin goblin("Dungeon Goblin");
            bool retreated = false;

            while (player.isAlive() && goblin.isAlive())
            {
                UI::showBattle(player, goblin);
                std::cout << "  [1] Attack\n\n  [2] Retreat\n\n  "
                          << UI::CYAN << "ACTION >> " << UI::RESET;

                int action = 0;
                if (!readChoice(action))
                {
                    std::cout << UI::RED << "\nInvalid input.\n"
                              << UI::RESET;
                    waitForEnter();
                    continue;
                }

                if (action == 1)
                {
                    std::cout << '\n';
                    player.attack(goblin);
                    if (goblin.isAlive())
                        goblin.attack(player);
                    if (player.isAlive() && goblin.isAlive())
                        waitForEnter();
                }
                else if (action == 2)
                {
                    retreated = true;
                    break;
                }
                else
                {
                    std::cout << UI::RED << "Unknown action. Choose 1 or 2.\n"
                              << UI::RESET;
                    waitForEnter();
                }
            }

            if (!retreated)
            {
                if (!player.isAlive())
                {
                    UI::showDefeat(player.getName());
                }
                else if (!goblin.isAlive())
                {
                    UI::showVictory(goblin.getName());
                    generateLoot(player.getInventory());
                }
                waitForEnter();
            }
            else
            {
                std::cout << "\n  " << UI::GOLD
                          << "You retreat from the dungeon. No reward acquired."
                          << UI::RESET << '\n';
                waitForEnter();
            }
            break;
        }

        case 4:
            std::cout << "\n  " << UI::PURPLE << "SESSION TERMINATED"
                      << UI::RESET << '\n';
            std::cout << "  Farewell, Hunter " << name << ".\n\n";
            return 0;

        default:
            std::cout << '\n'
                      << UI::RED << "  Unknown command. Try again."
                      << UI::RESET << '\n';
            waitForEnter();
        }
    }
}
