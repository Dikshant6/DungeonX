# ⚔️ DungeonX

### *Rise as a Hunter. Enter the Dungeon. Defy Your Limits.*

DungeonX is a console-based RPG built in **C++**, inspired by dark fantasy dungeon adventures and the Hunter progression genre.

Step into the role of a Hunter, manage your inventory, grow stronger, and prepare to face the dangers lurking beyond the dungeon gates.

More than just a game, DungeonX is a hands-on journey into **Object-Oriented Programming, modern C++, memory management, and software design** — building a game from the ground up, one system at a time.

---

## 🟣 Project Status

**Currently in development.**

DungeonX is being developed incrementally, starting with its core character system, item hierarchy, inventory management, and terminal interface before expanding into actual dungeon exploration and combat.

## ✨ Features

- **Hunter System** — Create a Hunter with a custom name and character stats.
- **Character Foundation** — Health, attack power, defence, mana, damage handling, and healing.
- **Inventory Management** — Add, remove, and organize weapons and potions.
- **Polymorphic Item System** — A shared item abstraction for different item types.
- **Interactive Terminal UI** — A command-driven interface with a dark-fantasy aesthetic.
- **Object-Oriented Architecture** — Designed around inheritance, abstraction, encapsulation, and runtime polymorphism.

*Features are being implemented and integrated progressively.*

## 🎮 The Vision

The goal is to build a playable RPG where every decision matters.

- Enter dungeons containing multiple rooms and encounters.
- Fight enemies of increasing strength.
- Defeat dungeon bosses to earn rewards and experience.
- Collect weapons, consume potions, and strengthen your Hunter.
- Progress through the Hunter levels, with the first version targeting Level 25.

Future versions may introduce advanced Hunter classes, specialized abilities, and additional progression systems.

## 🛠️ Tech Stack

| Technology | Purpose |
|---|---|
| C++17 | Core game logic |
| STL | Containers and standard utilities |
| Smart Pointers | Resource ownership and memory management |
| OOP | Game architecture and entity behaviour |
| ANSI Escape Codes | Terminal colors and interface styling |
| Git & GitHub | Version control and project tracking |

## 📁 Project Structure

```text
DungeonX/
├── assets/       # Game assets and resources
├── docs/         # Design documents and notes
├── include/      # Header files
├── src/          # Class implementations
├── tests/        # Component tests
├── main.cpp      # Application entry point
├── .gitignore
└── README.md
```

The structure may evolve as new game systems are introduced.

## 🚀 Getting Started

### Prerequisites

- A C++17-compatible compiler, such as GCC.
- A terminal emulator.
- Git (optional, for cloning the repository).

### Clone the Repository

```bash
git clone <YOUR_REPOSITORY_URL>
cd DungeonX
```

Replace `<YOUR_REPOSITORY_URL>` with your GitHub repository URL.

### Compile and Run

For the current Hunter interface:

```bash
g++ -std=c++17 main.cpp \
    src/Character.cpp \
    src/Hunter.cpp \
    -Iinclude -o DungeonX
```

Run the game:

```bash
./DungeonX
```

**Note:** As more systems are integrated into the main application, additional source files may need to be included in the compilation command.

## 🧠 What I'm Learning Through DungeonX

This project is also my practical C++ learning ground.

- Classes, objects, constructors, and destructors.
- Encapsulation and access control.
- Inheritance and abstract classes.
- Pure virtual functions and runtime polymorphism.
- Composition and relationships between game entities.
- `std::vector`, references, pointers, and smart pointers.
- Ownership and resource lifetime using `std::unique_ptr`.
- Separating declarations and implementations using header and source files.
- Testing, debugging, and incremental software development.

The objective is not merely to make the game work, but to understand **why the architecture works and how its components interact**.

## 🗺️ Development Roadmap

- [x] Define the initial game scope and architecture.
- [x] Implement the abstract `Character` foundation.
- [x] Implement the initial `Hunter` class.
- [x] Create the abstract `Item` hierarchy.
- [x] Implement initial `Weapon` and `Potion` classes.
- [x] Implement and test core inventory operations.
- [x] Create the first interactive terminal menu.
- [ ] Integrate inventory with the Hunter.
- [ ] Implement weapon equipment and potion consumption.
- [ ] Build the enemy hierarchy.
- [ ] Implement turn-based combat.
- [ ] Develop rooms, dungeons, and boss encounters.
- [ ] Add experience, rewards, and level progression.
- [ ] Polish gameplay, testing, and documentation.

## 🎯 Design Philosophy

DungeonX is being developed with a few principles in mind:

- **Understand before expanding.** Each system should have a clear responsibility.
- **Prefer clean architecture.** Keep game entities, inventory management, and gameplay flow separated.
- **Build incrementally.** Implement, test, integrate, and improve.
- **Keep the scope realistic.** Focus on a functional first version before introducing advanced mechanics.
- **Learn through implementation.** Every feature should strengthen both the game and my understanding of C++.

## 🔮 Future Possibilities

Once the first version is playable, DungeonX may expand with:

- Advanced Hunter classes and unique abilities.
- Rare weapons and special dungeon rewards.
- More enemy types and challenging bosses.
- Deeper progression and awakening systems.
- Improved terminal effects and combat presentation.

These are future possibilities, not promises for the current release.

---

## 👨‍💻 About the Project

DungeonX is an independent learning project built to combine my interest in RPGs with my goal of developing a deeper understanding of C++ and software engineering.

Every class, mechanic, and encounter is an opportunity to learn something new.

**The dungeon is still under construction. The Hunter's journey has just begun.**

---

*⚔️ Enter prepared. Leave stronger.*