// Created by Shalev Ben David.
#include "game.hpp"
#include "card.hpp"
#include <random>
#include <iostream>

void Game::assignCards() {
    // Create all cards and insert to main deck.
    for (int i = 1; i <= 13; i++) {
        this -> _main_deck.push_back(Card(i, "Hearts"));
        this -> _main_deck.push_back(Card(i, "Spades"));
        this -> _main_deck.push_back(Card(i, "Diamonds"));
        this -> _main_deck.push_back(Card(i, "Clubs"));
    }
    // Shuffle the main deck.
    std::random_device random_seed;
    std::shuffle(std::begin(this -> _main_deck), std::end(this -> _main_deck), random_seed);
    // Distribute the cards to the 2 players.
    this -> distributeCards();
}

// ****************** Distribute Cards From Main Deck To Both Players ******************
void Game::distributeCards() {
    // While the main deck isn't empty.
    while (this -> _main_deck) {
        // Give a card for each player from the main deck.
        this -> _B.getPlayerDeck().push_back(this -> _main_deck.back())
        this -> _main_deck.pop_back();
        this -> _A.getPlayerDeck().push_back(this -> _main_deck.back())
        this -> _main_deck.pop_back();
    }
}

// ****************** Declaring X As The Round Winner ******************
void Game::declareWinner(Player& X) {
    // Add the main deck cards to X winning deck.
    while (this -> _main_deck) {
        X.getPlayerDeck().push_back(this -> _main_deck.back())
        this -> _main_deck.pop_back();
    }
    // Add 1 to X's winning count.
    X.getNumOfWins()++;
}

// ****************** Each Player Puts A Card In The Main Deck ******************
void Game::putCards() {
    this -> main_deck.push_back(this -> _A.getPlayerDeck().back());
    this -> _A.getPlayerDeck().pop_back();
    this -> main_deck.push_back(this -> _B.getPlayerDeck().back());
    this -> _B.getPlayerDeck().pop_back();
}

// ****************** Playing A Turn ******************
void Game::playTurn() {
    // If the game already ended, throw exception.
    if (this -> _has_ended) {
        throw std::exception("The game already ended!");
    }
    bool round_end = false;
    // While this round still hasn't ended and there still cards left to play.
    while ((!round_end) && (this -> _A.stacksize() > 0) && (this -> _B.stacksize() > 0)) {
        // Each player puts a card in the main deck.
        Card card_value_A = this -> _A.getPlayerDeck().back();
        Card card_value_B = this -> _B.getPlayerDeck().back();
        this -> putCards();
        // If there is a draw, put another card upside down each in the main deck.
        if (card_value_A.getNum() == card_value_B.getNum()) {
            this -> putCards();
            this -> _num_of_draws++;
        }
        // Player A is the winner of this round.
        else if (card_value_A.getNum() == 2 && card_value_B.getNum() == ACE) {
            declareWinner(this -> _A);
            round_end = true;
        }
        // Player B is the winner of this round.
        else if (card_value_B.getNum() == 2 && card_value_A.getNum() == ACE) {
            declareWinner(this -> _B);
            round_end = true;
        }
        // Player A is the winner of this round.
        else if ((card_value_A.getNum() == ACE) || (card_value_A.getNum() > card_value_B.getNum())) {
            declareWinner(this -> _A);
            round_end = true;
        }
        // Player B is the winner of this round.
        else if ((card_value_B.getNum() == ACE) || (card_value_B.getNum() > card_value_A.getNum())) {
            declareWinner(this -> _B);
            round_end = true;
        }
    }
    // If the game has ended, distribute main deck && update has_ended.
    if ((this -> _A.stacksize() = 0) && (this -> _B.stacksize() == 0)) {
        this -> distributeCards();
        this -> _has_ended = true;
    }
}

void Game::printLastTurn() {
    std::cout << this -> turns.back() << std::endl;
}

// ****************** Play Until The End ******************
void Game::playAll() {
    // While the game hasn't ended yet.
    while (!(this -> has_ended)) {
        this -> playTurn();
    }
}

// ****************** Printing The Winner ******************
void Game::printWiner() {
    // If A is the winner, print him.
    if (this -> _A.cardesTaken() > this -> _B.cardesTaken()) {
        std::cout << "Winner is: " << this -> _A.getName() << "!" <<  std::endl;
    }
    // If B is the winner, print him.
    else if (this -> _A.cardesTaken() < this -> _B.cardesTaken()) {
        std::cout << "Winner is: " << this -> _B.getName() << "!" << std::endl;
    }
    // If there is no winner declared, throw exception.
    else {
        throw std::exception("No one has won!");
    }
}

// ****************** Printing Log Of All Turns ******************
void Game::printLog() {
    for (int i = 0; i < this -> _turns.size(); i++) {
        std::cout << this -> _turns[i] << std::endl;
    }
}

// ****************** Printing Stats ******************
void Game::printStats() {

}