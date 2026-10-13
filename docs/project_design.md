DungeonX --- Project Design

1. Project Overview

DungeonX is a console-based RPG developed in C++.

The project is designed to provide practical experience with
Object-Oriented Programming through the development of a small, playable
dungeon adventure.

The player begins as a Hunter and progresses through increasingly
difficult dungeons by defeating enemies, gaining experience, leveling
up, and collecting rewards.

The first version of DungeonX will focus on progression up to Level 25.
Advanced progression milestones such as Level 50, Level 75, and Level
100 are reserved for future versions.

The project intentionally keeps the first version manageable so that the
focus remains on clean C++ and OOP design rather than excessive game
complexity.

2. Project Objectives

The primary objectives of DungeonX are:

Build a small but playable console-based RPG.

Apply Object-Oriented Programming concepts in a practical
environment.

Design classes with clear and limited responsibilities.

Understand abstraction through abstract classes and pure virtual
functions.

Understand inheritance and runtime polymorphism through characters
and game entities.

Practice encapsulation and composition.

Practice STL containers such as vector.

Work with constructors, destructors, references, pointers, const,
and override.

Practice function overloading and friend functions where they have a
meaningful use.

Practice modular C++ development using separate header and source
files.

Write code that can be tested and extended without unnecessary
complexity.

3. Version 1 Scope

Player

The player controls a single Hero.

The Hero:

Has a user-defined name.

Starts as a Hunter.

Has a level and experience points.

Has health, attack, and defense-related statistics.

Can use items from an inventory.

Can fight enemies.

Can gain experience and level up.

Hero Progression

The first version supports progression from Level 1 through Level 25.

The Hero remains a Hunter throughout Version 1.

The class-awakening system is intentionally postponed to a future
version.

Enemies

Version 1 will contain a limited set of enemy types, introduced
progressively as the player advances.

Initial examples include:

Goblin

Orc

Boss

Additional enemy types may be introduced only if they fit the scope of
Version 1.

Enemies have their own combat statistics and behavior.

Enemy names are normally predefined by their type. Bosses may have a
specific name.

Dungeons

Each dungeon contains multiple encounters/rooms.

A dungeon does not end after a single enemy encounter.

The player must progress through multiple rooms and defeat the enemies
encountered throughout the dungeon.

Every dungeon contains a final Boss encounter.

Dungeons become progressively more difficult as the player advances.

Combat

The initial combat system will support:

Basic attack.

Taking damage.

Using available healing items.

Viewing relevant player/enemy information.

Defeating enemies.

Losing when the Hero's health reaches zero.

Combat should remain simple in Version 1 while providing enough behavior
to demonstrate polymorphism and object interaction.

Rewards

Defeated enemies can provide:

Experience points.

Potions/consumables.

Weapons or other simple items.

Bosses may provide better rewards than regular enemies.

Class-exclusive abilities are NOT part of dungeon loot.

4. Game Progression

The intended progression loop is:

Start Game
|
v
Create Hero
|
v
Hunter — Level 1
|
v
Enter Dungeon
|
v
Explore Multiple Rooms
|
v
Encounter Enemy
|
v
Battle
|
+---- Hero defeated ----> Game Over
|
v
Enemy defeated
|
v
Receive XP / Rewards
|
v
Continue Dungeon
|
v
Defeat Final Boss
|
v
Dungeon Cleared
|
v
Level Up / Continue Progression
|
v
Reach Level 25

Version 1 ends its progression target at Level 25.

5. Future Progression

The project is intentionally designed so that future versions can expand
the progression without requiring the entire game to be redesigned.

Version 2

Target progression:

Level 1--50

Special Dungeon at Level 50

Class Awakening

Advanced Hero classes

Possible classes:

Mage

Assassin

Healer

Necromancer

Other future classes

Version 3

Target progression:

Level 1--75

More enemy types

More difficult dungeons

More abilities and items

Version 4

Target progression:

Level 1--100

Further end-game content

Additional systems based on the lessons learned from earlier
versions

These future systems are intentionally not part of the Version 1
implementation.

6. Class Awakening --- Future Feature

At Level 50, a Special Dungeon will become available.

After successfully completing the Special Dungeon, the Hero will be
allowed to permanently choose an advanced class.

Examples:

Hunter
|
+---- Mage
|
+---- Assassin
|
+---- Healer
|
+---- Necromancer

Each advanced class will have one or more class-exclusive abilities.

A class-exclusive ability:

Belongs only to its corresponding class.

Cannot be randomly obtained from dungeon rewards.

Cannot be dropped by normal enemies.

Cannot be transferred to another class.

Is unlocked through the class-awakening/progression system.

This system is reserved for a future version and will not be implemented
in Version 1.

7. Initial Game Entities

The initial design is expected to contain entities such as:

Game
|
+-- Player
| |
| +-- Hero
| |
| +-- Inventory
|
+-- Character
| |
| +-- Hero
| |
| +-- Enemy
| |
| +-- Goblin
| +-- Orc
| +-- Boss
|
+-- Item
| |
| +-- Weapon
| +-- Potion
|
+-- Dungeon
|
+-- Room / Encounter

This diagram is a starting point, not a final class hierarchy.

The exact inheritance and composition relationships will be decided
during the architecture/design phase after evaluating the
responsibilities of each entity.

8. OOP Concepts to Demonstrate

DungeonX should provide meaningful opportunities to use:

Encapsulation

Keep internal state private/protected and expose controlled operations.

Examples:

Taking damage through a method.

Healing through a method.

Managing inventory through inventory operations.

Abstraction

Use abstract interfaces where multiple entities share a meaningful
common contract.

Potential examples:

Common character behavior.

Common item behavior.

Inheritance

Use inheritance where specialized entities genuinely represent
specialized versions of a common abstraction.

Potential examples:

Different enemy types.

Different item types.

Runtime Polymorphism

Use virtual functions when the game needs to interact with different
derived objects through a common interface.

Example concept:

Character\*
|
+---- Goblin
+---- Orc
+---- Boss

The exact implementation will be decided during design.

Composition

Use composition for strong "has-a" relationships.

Example:

Hero
|
+-- Inventory

Function Overloading

Use function overloading where multiple operations represent the same
conceptual action with different parameters.

Friend Functions

A friend function should only be introduced when there is a meaningful
reason for it to access private/protected state. It should not be added
merely to satisfy a checklist.

Constructors and Destructors

Use constructors to establish valid object state and destructors where
resource lifetime requires them.

9. Design Principles

The project should follow these principles:

Keep each class responsible for a focused part of the system.

Prefer composition when it represents the relationship better than
inheritance.

Do not create classes only because a concept exists in the game.

Do not force an OOP concept into the project without a reasonable
use case.

Avoid unnecessarily complicated systems in Version 1.

Keep game logic separate from user-interface/input code where
practical.

Prefer readable and maintainable C++ over clever code.

Build and test the project incrementally.

10. Version 1 Constraints

The following are intentionally excluded from the initial version:

Graphical rendering.

Complex enemy AI.

Procedural dungeon generation.

Large skill trees.

Class awakening.

Advanced equipment systems.

Multiplayer.

Networking.

Complex save/load architecture.

Large story/campaign systems.

These features may be considered later only after the core game is
stable.

11. Development Workflow

DungeonX will be developed in the following stages:

Requirements
|
v
Game Design
|
v
Class / Architecture Design
|
v
Header Interfaces
|
v
Implementation
|
v
Individual Testing
|
v
System Integration
|
v
Gameplay Testing
|
v
Refactoring
|
v
Documentation
|
v
GitHub Release

Each major feature should be implemented and tested before moving to the
next feature.

12. Planned Project Structure

DungeonX/
|
+-- include/ # Header files
|
+-- src/ # C++ implementation files
|
+-- tests/ # Component and feature tests
|
+-- docs/ # Project documentation and design notes
|
+-- assets/ # Future game assets/data
|
+-- main.cpp # Application entry point
|
+-- README.md # Public project documentation
|
+-- .gitignore

The structure may be expanded later if the project grows, but Version 1
should avoid unnecessary directories and abstractions.

13. Success Criteria for Version 1

Version 1 will be considered complete when:

A player can start a new game.

A Hero can be created with a custom name.

The Hero starts as a Hunter.

The Hero can progress from Level 1 toward Level 25.

The player can enter multiple dungeons.

Dungeons contain multiple encounters.

Different enemy types can appear.

Every dungeon has a final Boss encounter.

Combat works correctly.

The Hero can use basic items such as potions.

Enemies provide experience and rewards.

The Hero can level up.

Game-over and dungeon-completion states work correctly.

The code demonstrates the intended OOP concepts without unnecessary
complexity.

The project is organized, tested, documented, and committed to
GitHub.

14. Future Ideas

Potential future additions include:

Class awakening.

Class-exclusive abilities.

More Hero classes.

More enemy types.

Elite enemies.

Advanced Boss mechanics.

Equipment and rarity systems.

Better dungeon progression.

Save/load.

ASCII visual improvements.

More advanced combat mechanics.

Future ideas should be evaluated only after the current version is
stable.

15. Current Development Status

Version: 1.0 --- In Development

Current Target: Level 25

Current Player Class: Hunter

Current Focus: Requirements and OOP architecture design
