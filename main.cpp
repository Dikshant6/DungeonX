#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Hunter.h"

    namespace UI
{
    constexpr int WIDTH = 62;

    const std::string RESET = "\033[0m";
    const std::string PURPLE = "\033[38;5;141m";
    const std::string CYAN = "\033[38;5;117m";
    const std::string GREY = "\033[38;5;245m";
    const std::string WHITE = "\033[38;5;255m";
    const std::string RED = "\033[38;5;203m";

    void line(char symbol = '-')
    {
        std::cout << PURPLE << "  +"
                  << std::string(WIDTH, symbol)
                  << "+" << RESET << '\n';
    }

    void row(const std::string &text,
             const std::string &color = WHITE)
    {
        std::cout << PURPLE << "  |" << RESET
                  << color << std::left
                  << std::setw(WIDTH) << text
                  << RESET << PURPLE << "|" << RESET << '\n';
    }

    void centered(const std::string &text,
                  const std::string &color = WHITE)
    {
        int left = (WIDTH - static_cast<int>(text.size())) / 2;
        int right = WIDTH - static_cast<int>(text.size()) - left;

        std::cout << PURPLE << "  |" << RESET
                  << std::string(left, ' ')
                  << color << text << RESET
                  << std::string(right, ' ')
                  << PURPLE << "|" << RESET << '\n';
    }

    void showBanner()
    {
        std::cout << "\n";
        line('=');
        centered("D U N G E O N X", PURPLE);
        centered("H U N T E R   S Y S T E M", CYAN);
        line('=');
        centered("A W A K E N I N G   P R O T O C O L", GREY);
        line('=');
        std::cout << '\n';
    }

    void showMenu(const std::string &name)
    {
        line('=');
        centered("HUNTER COMMAND CENTER", PURPLE);
        line();

        row("  HUNTER  :  " + name, CYAN);
        row("  STATUS  :  ACTIVE", GREY);

        line();

        row("  [01]    Hunter Profile");
        row("");
        row("  [02]    Inventory");
        row("");
        row("  [03]    Enter the Dungeon");
        row("");
        row("  [04]    Terminate Session");

        line('=');
        row("  SYSTEM  >  Awaiting command...", PURPLE);
        line('=');

        std::cout << "\n  " << CYAN
                  << "COMMAND  >> " << RESET;
    }
}

int main()
{
    std::string name;

    UI::showBanner();

    std::cout << "  Enter Hunter name: ";
    std::getline(std::cin, name);

    if (name.find_first_not_of(" \t\n\r") ==
        std::string::npos)
    {
        name = "Unknown Hunter";
    }

    Hunter player(name);

    std::cout << "\n";
    UI::line('=');
    UI::row("  IDENTITY VERIFIED", UI::CYAN);
    UI::row("  Welcome, Hunter " + name + ".");
    UI::row("  Your journey begins now.", UI::GREY);
    UI::line('=');

    int choice = 0;

    while (true)
    {
        UI::showMenu(name);

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n');

            std::cout << "\n  " << UI::RED
                      << "Invalid command. Use 1-4."
                      << UI::RESET << "\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            std::cout << '\n';
            player.displayStats();
            break;

        case 2:
            std::cout << "\n  Inventory module pending integration.\n";
            break;

        case 3:
            std::cout << "\n  Dungeon gates detected.\n";
            std::cout << "  Combat module is being prepared.\n";
            break;

        case 4:
            std::cout << "\n  " << UI::PURPLE
                      << "SESSION TERMINATED"
                      << UI::RESET << '\n';
            std::cout << "  Farewell, Hunter "
                      << name << ".\n\n";
            return 0;

        default:
            std::cout << "\n  " << UI::RED
                      << "Unknown command. Try again."
                      << UI::RESET << '\n';
        }
    }
}