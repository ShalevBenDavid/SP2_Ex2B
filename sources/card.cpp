// Created by Shalev Ben David.
#include "card.hpp"
using namespace ariel;

// ****************** To String Method ******************
std::string Card::toString() {
    switch (this -> _num) {
        case ACE:
            return "Ace of " + this -> _type;
        case JACK:
            return "Jack of " + this -> _type;
        case QUEEN:
            return "Queen of " + this -> _type;
        case KING:
            return "king of " + this -> _type;
        default:
            return std::to_string(this -> _num) + " of " + this -> _type;
    }
}