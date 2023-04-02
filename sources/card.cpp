// Created by Shalev Ben David.
#include "card.hpp"
#include <string>

std::string Card::toString() {
    switch (this -> num) {
        case 1:
            return "Ace of " + this -> type;
        case 11:
            return "Jack of " + this -> type;
        case 12:
            return "Queen of " + this -> type;
        case 13:
            return "king of " + this -> type;
        default:
            return std::to_string(this -> num) + " of " + this -> type;
    }
}