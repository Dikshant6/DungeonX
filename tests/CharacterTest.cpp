#include "Character.h"
#include <iostream>

class TestCharacter : public Character {
public:
    TestCharacter(std::string name) : Character(name) {}

    void attack(Character& target) override {
        std::cout << name << " attacks " << std::endl;
    }
};

int main() {

    std::cout << "\n===== CHARACTER TEST START =====\n\n";

    TestCharacter hero("Test Hero");

    // 1. Initial state
    std::cout << "--- Initial Stats ---\n";
    hero.displayStats();

    // 2. isAlive()
    std::cout << "\n--- Alive Test ---\n";
    std::cout << "Is alive: "
              << (hero.isAlive() ? "YES" : "NO")
              << std::endl;

    // 3. takeDamage()
    std::cout << "\n--- Damage Test ---\n";
    hero.takeDamage(30);
    hero.displayStats();

    // 4. Heal
    std::cout << "\n--- Heal Test ---\n";
    hero.heal(20);
    hero.displayStats();

    // 5. Damage greater than current health
    std::cout << "\n--- Fatal Damage Test ---\n";
    hero.takeDamage(200);
    hero.displayStats();

    std::cout << "Is alive: " << (hero.isAlive() ? "YES" : "NO") << std::endl;

    // 6. Negative damage
    std::cout << "\n--- Negative Damage Test ---\n";
    hero.takeDamage(-50);
    hero.displayStats();

    // 7. Healing a dead character
    std::cout << "\n--- Heal Dead Character Test ---\n";
    hero.heal(50);
    hero.displayStats();

    // 8. Negative healing
    std::cout << "\n--- Negative Heal Test ---\n";
    hero.heal(-50);
    hero.displayStats();

    std::cout << "\n===== CHARACTER TEST END =====\n";

    return 0;
}