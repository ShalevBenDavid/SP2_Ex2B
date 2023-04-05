// Created by Shalev Ben David.
#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <stdexcept>
namespace ariel {}

const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

class Card {
    // Private attributes.
    int _num;
    std::string _type;

public:
    // Constructor.
    Card(int num, const std::string &type) {
        // Throw an exception if it is invalid type.
        if (num < ACE || num > KING) {
            throw std::invalid_argument("Num is out of range!");
        }
        this -> _num = num;
        this -> _type = type;
    }

    // Get method.
    int& getNum() { return _num; }
    const std::string& getName() { return _type; }

    // ToString method.
    std::string toString();
};

#endif