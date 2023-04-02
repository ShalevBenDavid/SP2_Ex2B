// Created by Shalev Ben David.
#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
    // Private attributes.
    int num;
    std::string type;

public:
    // Constructor.
    Card(int num, const std::string &type) {
        // Throw an exception if it is invalid type.
        if (num < 1 || num > 13) {
            throw std::invalid_argument("Num is out of range!");
        }
        this -> num = num;
        this -> type = type;
    }
    // Destructor.
    ~Card() {}
    // Get method.
    const int& getNum() { return num; }
    const std::string& getName() { return type; }
    // ToString method.
    std::string toString();
};

#endif