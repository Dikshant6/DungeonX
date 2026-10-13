
#include "Dungeon.h"

#include <iostream>
#include <utility>

Dungeon::Dungeon(const std::string &name)
    : name(name),
      currentRoomIndex(0) {}

const std::string &Dungeon::getName() const
{
    return name;
}

void Dungeon::addRoom(Room room)
{
    rooms.push_back(std::move(room));
}

Room *Dungeon::getCurrentRoom()
{
    if (isCompleted())
    {
        return nullptr;
    }

    return &rooms[currentRoomIndex];
}

const Room *Dungeon::getCurrentRoom() const
{
    if (isCompleted())
    {
        return nullptr;
    }

    return &rooms[currentRoomIndex];
}

bool Dungeon::moveToNextRoom()
{
    if (isCompleted())
    {
        return false;
    }

    // Current room must be cleared first.
    if (rooms[currentRoomIndex].hasEnemies())
    {
        return false;
    }

    ++currentRoomIndex;
    return !isCompleted();
}

bool Dungeon::isCompleted() const
{
    return currentRoomIndex >= rooms.size();
}

std::size_t Dungeon::getCurrentRoomNumber() const
{
    if (isCompleted())
    {
        return rooms.size();
    }

    return currentRoomIndex + 1;
}

std::size_t Dungeon::getTotalRooms() const
{
    return rooms.size();
}

void Dungeon::displayProgress() const
{
    std::cout << "\n========== DUNGEON STATUS ==========\n";
    std::cout << "Dungeon: " << name << '\n';
    std::cout << "Progress: " << getCurrentRoomNumber()
              << " / " << getTotalRooms() << '\n';

    if (isCompleted())
    {
        std::cout << "Status: DUNGEON CLEARED!\n";
    }
    else
    {
        std::cout << "Status: IN PROGRESS\n";
        std::cout << "Current room: "
                  << rooms[currentRoomIndex].getName() << '\n';
    }

    std::cout << "====================================\n";
}
