// Created by Shalev Ben David.
#ifndef CARD_H
#define CARD_H
#include <string>

const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

class Card {
    // Private attributes.
    int num;
    std::string type;

public:
    // Constructor.
    Card(int num, const std::string &type) {
        // Throw an exception if it is invalid type.
        if (num < ACE || num > KING) {
            throw std::invalid_argument("Num is out of range!");
        }
        this -> num = num;
        this -> type = type;
    }
    // Get method.
    const int& getNum() { return num; }
    const std::string& getName() { return type; }
    // ToString method.
    std::string toString();
};

#endif