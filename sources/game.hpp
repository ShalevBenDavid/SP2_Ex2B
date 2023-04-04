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
    Player _A;
    Player _B;
    std::vector<Card> _main_deck;
    std::vector<std::string> _turns;
    int _num_of_draws;
    bool _has_ended;

public:
    // Constructor.
    Game(Player& A, Player& B) :
    _A(A), _B(B), _num_of_draws(0), _has_ended(false) {
        if (&_A == &_B) {
            throw std::invalid_argument("The game already ended!");
        }
        assignCards();
    }

    // Methods.
    void assignCards();
    void distributeCards();
    void declareWinner(Player);
    void putCards();
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

    // Get methods.
    Player& getPlayerA() { return _A; }
    Player& getPlayerB() { return _B; }
    std::vector<Card>& getMainDeck() {return _main_deck; }
    std::vector<Card>& getTurns() {return _turns; }
    int& getNumOfDraws() {return _num_of_draws; }
    bool& getHasEnded() {return _has_ended; }

    // ToString method.
    std::string toString() { return _A.toString() + "\n" + _B.toString(); }
};

#endif