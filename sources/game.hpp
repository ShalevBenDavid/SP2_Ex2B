// Created by Shalev Ben David.
#ifndef GAME_H
#define GAME_H
#include "player.hpp"
#include "card.hpp"
#include <string>
#include <vector>

const int FULL_DECK = 26;

class Game {
    // Private attributes.
    Player A;
    Player B;
    std::vector<Card> main_deck;
    std::vector<std::string> turns;
    bool has_won;
    bool has_ended;
public:
    // Constructor.
    Game(const Player& player1, const Player& player2) {
        A = player1;
        B = player2;
        assignCards();
        A.getStackSize() = FULL_DECK;
        B.getStackSize() = FULL_DECK;
        has_won = false;
        has_ended = false;
    }
    // Destructor.
    ~Game() {}
    // Methods.
    void assignCards();
    void distributeCards();
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    // Get methods.
    Player& getPlayerA() { return A; }
    Player& getPlayerB() { return B; }
    std::vector<Card>& getMainDeck() {return main_deck; }
    // ToString method.
    std::string toString() { return A.toString() + "\n" + B.toString(); }
};

#endif