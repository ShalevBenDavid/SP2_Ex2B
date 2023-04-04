// Created by Shalev Ben David.
#ifndef GAME_H
#define GAME_H
#include "player.hpp"
#include "card.hpp"
#include <string>
#include <stdexcept>
#include <vector>

const int FULL_DECK = 26;

class Game {
    // Private attributes.
    Player A;
    Player B;
    std::vector<Card> _main_deck;
    std::vector<std::string> _turns;
    int _num_of_draws;
    bool _has_ended;

public:
    // Constructor.
    Game(Player& playerA, Player& playerB) :
    A(playerA), B(playerB), _num_of_draws(0), _has_ended(false) {
        if (&A == &B) {
            throw std::invalid_argument("The game already ended!");
        }
        assignCards();
    }

    // Methods.
    void assignCards();
    void distributeCards();
    void declareWinner(Player& winner);
    void putCards();
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

    // Get methods.
    Player& getPlayerA() { return A; }
    Player& getPlayerB() { return B; }
    std::vector<Card>& getMainDeck() {return _main_deck; }
    std::vector<std::string>& getTurns() {return _turns; }
    int& getNumOfDraws() {return _num_of_draws; }
    bool& getHasEnded() {return _has_ended; }

    // ToString method.
    std::string toString() { return A.toString() + "\n" + B.toString(); }
};

#endif