// Created by Shalev Ben David.
#include "game.hpp"
#include "card.hpp"
#include <random>

// ****************** Create The Cards And Distribute Them ******************
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
    this -> distributeCards(this -> A.getPlayerDeck(), this -> B.getPlayerDeck());
}

// ****************** Distribute Cards From Main Deck To Both Players ******************
void Game::distributeCards(std::vector<Card>& deck_A, std::vector<Card>& deck_B) {
    // While the main deck isn't empty.
    while (!(this -> _main_deck.empty())) {
        // Give a card for each player from the main deck to his winning/curren deck.
        deck_B.push_back(this -> _main_deck.back());
        this -> _main_deck.pop_back();
        deck_A.push_back(this -> _main_deck.back());
        this -> _main_deck.pop_back();
    }
}

// ****************** Declaring X As The Round Winner ******************
void Game::declareWinner(Player& winner) {
    // Add the main deck cards to X winning deck.
    while (!(this -> _main_deck.empty())) {
        winner.getWinDeck().push_back(this -> _main_deck.back());
        this -> _main_deck.pop_back();
    }
    // Add 1 to X's winning count.
    winner.getNumOfWins()++;
}

// ****************** Each Player Puts A Card In The Main Deck ******************
void Game::putCards() {
    this -> _main_deck.push_back(this -> A.getPlayerDeck().back());
    this -> A.getPlayerDeck().pop_back();
    this -> _main_deck.push_back(this -> B.getPlayerDeck().back());
    this -> B.getPlayerDeck().pop_back();
}

// ****************** Playing A Turn ******************
void Game::playTurn() {
    // If it is the same player, throw exception.
    if (&(this -> A) == &(this -> B)) {
        throw std::invalid_argument("You need 2 distinct players for a game!");
    }
    // If the game already ended, throw exception.
    if (this -> _has_ended) {
        throw std::runtime_error("The game already ended!");
    }
    bool round_end = false;
    // The name of the round's winner.
    std::string winner;
    // Create a string that represents current turn.
    std::string turn;
    // While this round still hasn't ended and there still cards left to play.
    while ((!round_end) && (this -> A.stacksize() > 0) && (this -> B.stacksize() > 0)) {
        // Each player puts a card in the main deck.
        Card card_value_A = this -> A.getPlayerDeck().back();
        Card card_value_B = this -> B.getPlayerDeck().back();
        this -> putCards();
        // If there is a draw, put another card upside down each in the main deck.
        if (card_value_A.getNum() == card_value_B.getNum()) {
            this -> _num_of_draws++;
            // Update current turn.
            turn += this -> A.getName() + " played " + card_value_A.toString() + " "
                    + this -> B.getName() + " played " + card_value_B.toString() + ". Draw. ";
            // They can't put more cards. End the round.
            if ((this -> A.stacksize() == 0) && (this -> B.stacksize() == 0)) {
                break;
            }
            else {
                // Put 2 cards upside down.
                this -> putCards();
            }
        }
        // Player A is the winner of this round.
        else if ((card_value_A.getNum() == 2 && card_value_B.getNum() == ACE) ||
                (card_value_A.getNum() == ACE) ||
                (card_value_A.getNum() > card_value_B.getNum() && card_value_B.getNum() != ACE)) {
            declareWinner(this -> A);
            winner = this -> A.getName();
            round_end = true;
        }
        // Player B is the winner of this round.
        else if ((card_value_B.getNum() == 2 && card_value_A.getNum() == ACE) ||
                 (card_value_B.getNum() == ACE) ||
                 (card_value_B.getNum() > card_value_A.getNum() && card_value_A.getNum() != ACE)) {
            declareWinner(this -> B);
            winner = this -> B.getName();
            round_end = true;
        }
        // If the round ended with a winner.
        if (round_end) {
            // Update current turn.
            turn += this -> A.getName() + " played " + card_value_A.toString() + " "
                    + this -> B.getName() + " played " + card_value_B.toString() + ". " + winner + " wins.";
        }
    }
    // Add current turn to the turns vector.
    if (!(turn.empty())) {
        this -> _turns.push_back(turn);
    }
    // If the game has ended, distribute main deck && update has_ended.
    if ((this -> A.stacksize() == 0) && (this -> B.stacksize() == 0)) {
        this -> distributeCards(this -> A.getWinDeck(), this -> B.getWinDeck());
        this -> _has_ended = true;
    }
}

// ****************** Prints the last turn. ******************
void Game::printLastTurn() {
    std::cout << "-------------------------> Printing Last Turn <-------------------------" << std::endl;
    if (!(this -> _turns.empty())) {
        std::cout << this->_turns.back() << std::endl;
    }
    std::cout << "\n";
}

// ****************** Play Until The End ******************
void Game::playAll() {
    // While the game hasn't ended yet.
    while (!(this -> _has_ended)) {
        this -> playTurn();
    }
}

// ****************** Printing The Winner ******************
void Game::printWiner() {
    // If A is the winner, print him.
    if (this -> A.cardesTaken() > this -> B.cardesTaken()) {
        std::cout << "Winner is player A: " << this -> A.getName() << "!" <<  std::endl;
    }
    // If B is the winner, print him.
    else if (this -> A.cardesTaken() < this -> B.cardesTaken()) {
        std::cout << "Winner is player B: " << this -> B.getName() << "!" << std::endl;
    }
    // If there is no winner declared, throw exception.
    else {
        std::cout << "No one has won!" << std::endl;
    }
}

// ****************** Printing Log Of All Turns ******************
void Game::printLog() {
    std::cout << "-----------------------------> Printing Log <-----------------------------" << std::endl;
    for (size_t i = 0; i < this -> _turns.size(); i++) {
        std::cout << this -> _turns[i] << std::endl;
    }
    std::cout << "\n";
}

// ****************** Printing Stats ******************
void Game::printStats() {
    std::cout << "---------------------------> Printing Stats <---------------------------" << std::endl;
    std::cout << this -> A.toString() << std::endl;
    std::cout << this -> B.toString() << std::endl;
    std::cout << "[Draws: " << std::to_string(this -> _num_of_draws) << "]" << std::endl;
    std::cout << "[Draw Rate: " << std::to_string(((double) this -> _num_of_draws / 26) * 100) << "%]" << std::endl;
    std::cout << "\n";
}

std::string Game::toString() {
    std::string info;
    info += "[Player A: " + this -> A.getName() + "]\n";
    info += "[Player B: " + this -> B.getName() + "]\n";
    // The game's main deck.
    info += "[Main Deck: | ";
    for (size_t i = 0; i < this -> _main_deck.size(); i++){
        info += this -> _main_deck[i].toString() + " | ";
    }
    info += "]\n";
    std::string ans = this -> _has_ended ? "Yes" : "No";
    info += "Game Ended? " + ans + ".\n";
    return info;
}