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

void Game::playTurn() {
    if (has_ended) {
        throw std::exception("The game already ended!");
    }

}

void Game::printLastTurn() {
    std::cout << this -> turns.back() << std::endl;
}

void playAll() {
}

void Game::printWiner() {
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

void Game::printLog() {

}

void Game::printStats() {

}