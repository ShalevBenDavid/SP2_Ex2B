// Created by Shalev Ben David.
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "card.hpp"

class Player {
    // Private attributes.
    std::string _name;
    int _num_of_wins;
    std::vector <Card> _player_deck;
    std::vector <Card> _win_deck;

public:
    // Constructor.
    Player(const std::string &player_name = "") :
    _name(player_name), _num_of_wins(0) {}

    // Get method.
    const std::string& getName() { return _name; }
    int stacksize() { return _player_deck.size(); }
    int cardesTaken() { return _win_deck.size(); }
    int& getNumOfWins() { return _num_of_wins; }
    std::vector<Card>& getPlayerDeck() {return _player_deck; }

    // Set method.
    void setName(const std::string &new_name) { _name = new_name; }

    // ToString method.
    std::string toString() { return "[Player name: " + _name + "]"; }
};

#endif