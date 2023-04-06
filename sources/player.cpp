// Created by Shalev Ben David.
#include "player.hpp"
using namespace ariel;

// ****************** To String Method ******************
std::string Player::toString() {
    std::string info;
    info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Player name: " + this -> _name + " >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    info += "[Wins: " + std::to_string(this -> _num_of_wins) + "]\n";
    info += "[Win Rate: " + std::to_string(((double) this -> _num_of_wins / 26) * 100) + "%]\n";
    info += "[Cards Won: " + std::to_string(this -> _win_deck.size()) + "]\n";
    // The player's current deck.
    info += "[Current Deck: | ";
    for (size_t i = 0; i < this -> _player_deck.size(); i++){
        info += this -> _player_deck[i].toString() + " | ";
    }
    info += "]\n";
    // The player's current winning deck (cards won).
    info += "[Winning Deck: | ";
    for (size_t i = 0; i < this -> _win_deck.size(); i++){
        info += this -> _win_deck[i].toString() + " | ";
    }
    info += "]\n";

    return info;
}