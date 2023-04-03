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
    int num_of_wins;
    std::vector <Card> player_deck;
    std::vector <Card> win_deck;

public:
    // Constructor.
    Player(const std::string &player_name = "") :
    name(player_name),
    num_of_wins(EMPTY_DECK)
    {}
    // Methods.

    // Get method.
    const std::string& getName() { return name; }
    int stacksize() { return player_deck.size(); }
    int cardesTaken() { return win_deck.size(); }
    int& getNumOfWins() { return num_of_wins; }
    std::vector<Card>& getPlayerDeck() {return player_deck; }
    // Set method.
    void setName(const std::string &new_name) { name = new_name; }
    // ToString method.
    std::string toString() { return "[Player name: " + name + "]"; }
};

#endif