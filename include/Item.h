#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    protected:
        std::string name;

    public:
        Item(std::string name);
        virtual ~Item() = default;

        std::string getName() const;
        virtual void use() = 0;
        virtual void displayInfo() const = 0;
};

#endif // !ITEM_H