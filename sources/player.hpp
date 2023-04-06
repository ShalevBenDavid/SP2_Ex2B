// Created by Shalev Ben David.
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "card.hpp"
namespace ariel {}

class Player {
    // Private attributes.
    std::string _name;
    int _num_of_wins;
    std::vector <Card> _player_deck;
    std::vector <Card> _win_deck;
    bool _in_game;

public:
    // Constructor.
    Player(const std::string &player_name = "") :
    _name(player_name), _num_of_wins(0), _in_game(false) {}

    // Get method.
    const std::string& getName() { return _name; }
    size_t stacksize() { return _player_deck.size(); }
    size_t cardesTaken() { return _win_deck.size(); }
    int& getNumOfWins() { return _num_of_wins; }
    std::vector<Card>& getPlayerDeck() {return _player_deck; }
    std::vector<Card>& getWinDeck() {return _win_deck; }
    bool& getInGame() { return _in_game; }

    // Set method.
    void setName(const std::string &new_name) { _name = new_name; }

    // ToString method.
    std::string toString();
};

#endif