// Created by Shalev Ben David.
#include "card.hpp"
#include <string>

std::string Card::toString() {
    switch (this -> num) {
        case ACE:
            return "Ace of " + this -> type;
        case JACK:
            return "Jack of " + this -> type;
        case QUEEN:
            return "Queen of " + this -> type;
        case KING:
            return "king of " + this -> type;
        default:
            return std::to_string(this -> num) + " of " + this -> type;
    }
}