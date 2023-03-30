// Created by Shalev Ben David.
#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
    // Private attributes.
    int type;
public:
    // Constructor.
    Card(int type = 1) : {
        // Throw an exception if it is invalid type.
        if (type < 1 || type > 13) {
            throw std::invalid_argument("Type is out of range!");
        }
        this -> type = type;
    }
    // Destructor.
    ~Card() {}
    // Get method.
    int& getType() { return type; }
};

#endif