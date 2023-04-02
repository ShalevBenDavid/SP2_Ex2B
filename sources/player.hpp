// Created by Shalev Ben David.
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "card.hpp"

const int EMPTY_DECK = 0;

class Player {
    // Private attributes.
    std::string name;
    int stack_size;
    int cards_taken;
    std::vector <Card> player_deck;

public:
    // Constructor.
    Player(const std::string &player_name = "") :
    name(player_name),
    stack_size(EMPTY_DECK),
    cards_taken(EMPTY_DECK)
    {}
    // Destructor.
    ~Player() {}
    // Methods.
    void stacksize() { std::cout << name << " stack's size: " << stack_size << std::endl; }
    void cardesTaken() { std::cout << name << " cards won: " << cards_taken << std::endl; }
    // Get method.
    const std::string& getName() { return name; }
    int& getStackSize() { return stack_size; }
    int& getCardsTaken() { return cards_taken; }
    std::vector<Card>& getPlayerDeck() {return player_deck; }
    // Set method.
    void setName(const std::string &new_name) { name = new_name; }
    // ToString method.
    std::string toString() { return "[Player name: " + name + "]"; }
};

#endif