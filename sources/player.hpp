// Created by Shalev Ben David.
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>

const int FULL_DECK = 26;
const int EMPTY_DECK = 0;

namespace ariel {

    class Player {
        // Private attributes.
        std::string name;
        int stack_size;
        int cards_taken;
        vector<Card> player_deck;

    public:
        // Constructor.
        Player(const std::string &player_name = "") : name(player_name){
            this -> stack_size = FULL_DECK;
            this -> cards_taken = EMPTY_DECK;
        }
        // Destructor.
        ~Player() {}
        // Get method.
        const std::string& getName() { return name; }
        int& stacksize() { return stack_size; }
        int& cardesTaken() { return cards_taken; }
        // Set method.
        void setName(const std::string &new_name) { name = new_name; }
        // ToString method.
        std::string toString() { return "[Player name: " + name + "]"; }
    };
}

#endif