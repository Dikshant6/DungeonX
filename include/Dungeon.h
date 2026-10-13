
#ifndef DUNGEON_H
#define DUNGEON_H

#include <cstddef>
#include <string>
#include <vector>

#include "Room.h"

class Dungeon
{
private:
    std::string name;
    std::vector<Room> rooms;
    std::size_t currentRoomIndex;

public:
    explicit Dungeon(const std::string &name);

    const std::string &getName() const;

    void addRoom(Room room);

    Room *getCurrentRoom();
    const Room *getCurrentRoom() const;

    bool moveToNextRoom();
    bool isCompleted() const;

    std::size_t getCurrentRoomNumber() const;
    std::size_t getTotalRooms() const;

    void displayProgress() const;
};

#endif
