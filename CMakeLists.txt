
cmake_minimum_required(VERSION 3.20)

project(DungeonX
    VERSION 0.1.0
    LANGUAGES CXX
)

# Use modern C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Game executable and its source files
add_executable(DungeonX
    main.cpp
    src/Character.cpp
    src/Hunter.cpp
    src/Inventory.cpp
    src/Item.cpp
    src/Weapon.cpp
    src/Potion.cpp
    src/Goblin.cpp
    src/Room.cpp
    src/Dungeon.cpp
)

# Find project headers inside include/
target_include_directories(DungeonX
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Helpful compiler warnings
target_compile_options(DungeonX
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

