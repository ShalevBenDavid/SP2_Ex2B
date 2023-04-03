// Created by Shalev Ben David.
#include "game.hpp"
#include "card.hpp"
#include <random>
#include <iostream>

void Game::assignCards() {
    // Create all cards and insert to main deck.
    for (int i = 1; i <= 13; i++) {
        this -> main_deck.push_back(Card(i, "Hearts"));
        this -> main_deck.push_back(Card(i, "Spades"));
        this -> main_deck.push_back(Card(i, "Diamonds"));
        this -> main_deck.push_back(Card(i, "Clubs"));
    }
    // Shuffle the main deck.
    std::random_device random_seed;
    std::shuffle(std::begin(this -> main_deck), std::end(this -> main_deck), random_seed);
    // Distribute the cards to the 2 players.
    this -> distributeCards();
}

void Game::distributeCards() {
    // While the main deck isn't empty.
    while (this -> main_deck) {
        // Give a card for each player from the main deck.
        this -> A.getPlayerDeck().push_back(this -> main_deck.back())
        this -> main_deck.pop_back();
        this -> B.getPlayerDeck().push_back(this -> main_deck.back())
        this -> main_deck.pop_back();
    }
}

// ****************** Declaring X As The Round Winner ******************
void Game::declareWinner(Player& X) {
    // Add the main deck cards to X winning deck.
    while (this -> main_deck) {
        X.getPlayerDeck().push_back(this -> main_deck.back())
        this -> main_deck.pop_back();
    }
    // Add 1 to X's winning count.
    X.getNumOfWins()++;
}

// ****************** Playing A Turn ******************
void Game::playTurn() {
    // If the game already ended, throw exception.
    if (this -> has_ended) {
        throw std::exception("The game already ended!");
    }
    bool round_end = false;
    // While this round still hasn't ended and there still cards left to play.
    while ((!round_end) && (this -> A.stacksize() > 0)) {
        // Each player puts a card in the main deck.
        Card card_value_A = this -> A.getPlayerDeck().back();
        this -> A.getPlayerDeck().pop_back();
        this -> main_deck.push_back(card_value_A);
        Card card_value_B = B.getPlayerDeck().back();
        this -> B.getPlayerDeck().pop_back();
        this -> main_deck.push_back(card_value_B);
        // Comparing cards.
        // If there is a draw, put another card upside down each in the main deck.
        if (card_value_A.getNum() == card_value_B.getNum()) {
            this -> main_deck.push_back(this -> A.getPlayerDeck().back());
            this -> A.getPlayerDeck().pop_back();
            this -> main_deck.push_back(this -> B.getPlayerDeck().back());
            this -> B.getPlayerDeck().pop_back();
            this -> num_of_draws++;
        }
        // Player A is the winner of this round.
        else if (card_value_A.getNum() == 2 && card_value_B.getNum() == ACE) {
            declareWinner(A);
            round_end = true;
        }
        // Player B is the winner of this round.
        else if (card_value_B.getNum() == 2 && card_value_A.getNum() == ACE) {
            declareWinner(B);
            round_end = true;
        }
        // Player A is the winner of this round.
        else if ((card_value_A.getNum() == ACE) || (card_value_A.getNum() > card_value_B.getNum())) {
            declareWinner(A);
            round_end = true;
        }
            // Player B is the winner of this round.
        else if ((card_value_B.getNum() == ACE) || (card_value_B.getNum() > card_value_A.getNum())) {
            declareWinner(B);
            round_end = true;
        }
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
    // If there is no winner declared, throw exception.
    if (!(this -> has_won)) {
        throw std::exception("No one has won!");
    }
    if (this -> A.getCardsTaken() > this -> B.getCardsTaken()) {
        std::cout << "Winner is: " << this -> A.getName() << "!" <<  std::endl;
    }
    else {
        std::cout << "Winner is: " << this -> B.getName() << "!" << std::endl;
    }
}

// ****************** Printing Log Of All Turns ******************
void Game::printLog() {
    for (int i = 0; i < this -> turns.size(); i++) {
        std::cout << this -> turns[i] << std::endl;
    }
}

void Game::printStats() {

}