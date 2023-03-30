// Created by Shalev Ben David.
#ifndef GAME_H
#define GAME_H
#include "player.hpp"
#include <string>
#include <vector>
using namespace ariel::Player;

class Game {
    // Private attributes.
    Player A;
    Player B;
    vector<Card> main_deck;

public:
    // Constructor.
    Game(const Player& player1, const Player& player2) : A(player1), B(player2) {}
    // Destructor.
    ~Game() {}
    // Methods.
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    // Get methods.
    Player& getPlayerA() { return A; }
    Player& getPlayerB() { return B; }
    // ToString method.
    std::string toString() { return A.toString() + "\n" + B.toString(); }
};

#endif