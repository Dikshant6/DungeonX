#include "Item.h"

Item::Item(std::string name) : name(name) {}

std::string Item::getName() const
{
    return name;
}
