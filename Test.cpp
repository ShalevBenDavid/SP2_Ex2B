// Created by Shalev Ben David.
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"

TEST_CASE("Case 1: Beginning and end of the game.") {
    // Creating 2 players and the game.
    Player A("Alice");
    Player B("Bob");
    // ---- Testing: Check the # of cards of each player before starting.
    // ---- Expecting: 0 cards each.
    CHECK(A.stacksize() == 0);
    CHECK(B.stacksize() == 0);
    Game game(A, B);
    // ---- Testing: Checking the last turn and stats before starting the game.
    // ---- Expecting: Should throw exception.
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printLog());
    // ---- Testing: Checking who won before starting the game.
    // ---- Expecting: Should throw exception.
    CHECK_THROWS(game.printWiner());
    // ---- Testing: Check the # of cards of each player when starting.
    // ---- Expecting: 26 cards each.
    CHECK(A.stacksize() == 26);
    CHECK(B.stacksize() == 26);
    // ---- Testing: Check the # of cards that each player won before starting.
    // ---- Expecting: 0 cards each.
    CHECK(A.cardesTaken() == 0);
    CHECK(B.cardesTaken() == 0);
    // Play till the end of the game.
    game.playAll();
    // ---- Testing: Checking the # of cards of each player when finishing.
    // ---- Expecting: 0 cards each.
    CHECK(A.stacksize() == 0);
    CHECK(B.stacksize() == 0);
    // ---- Testing: Playing another round even when the game is over.
    // ---- Expecting: Should throw exception.
    CHECK_THROWS(game.playTurn());
    // ---- Testing: Playing till the end even when the game is over.
    // ---- Expecting: Should throw exception.
    CHECK_THROWS(game.playAll());
}

TEST_CASE("Case 2: During and after 5 games.") {
    // Creating 2 players and the game.
    Player A("Alice");
    Player B("Bob");
    Game game(A, B);
    // Each player starts with 26 cards in the deck.
    int last_round_stack = 26;
    // Save the last # of winning cards for each player.
    int num_of_cards_wonA = 0;
    int num_of_cards_wonB = 0;
    // Play 5 rounds (or until the game ends).
    for (int i = 1; i <= 5; i++) {
        game.playTurn();
        // ---- Testing: Checking each player has the right number of cards in this turn.
        // ---- Expecting: In the i turn, each player should have 26-i cards at most.
        CHECK(A.stacksize() <= 26 - i);
        CHECK(B.stacksize() <= 26 - i);
        // Calculating this rounds profit.
        int current_round_profit = 2 * (last_round_stack - A.stacksize());
        // Updating this round stack.
        last_round_stack = A.stacksize();
        // Either A won this round or B won this round or no one won.
        bool A_won = num_of_cards_wonA + current_round_profit == A.cardesTaken();
        bool B_won = num_of_cards_wonB + current_round_profit == B.cardesTaken();
        bool no_one_won = (num_of_cards_wonA == A.cardesTaken()) && (num_of_cards_wonB == B.cardesTaken());
        if (A_won || B_won) {
            // ---- Testing: Checking that the total cards won in this round equals this round profit.
            // ---- Expecting: True.
            CHECK(A.cardesTaken() + B.cardesTaken() - num_of_cards_wonA - num_of_cards_wonB == current_round_profit);
        }
        // Update the # of cards won accordingly.
        num_of_cards_wonA = A.cardesTaken();
        num_of_cards_wonB = B.cardesTaken();
        // ---- Testing: Checking that either A or B won this round or no one won.
        // ---- Expecting: True.
        CHECK((A_won || B_won || no_one_won));
        // ---- Testing: Checking that the sum of the cards in the game is 52.
        // ---- Expecting: True.
        CHECK(A.cardesTaken() + A.stacksize() + B.cardesTaken() + B.stacksize() == 52);
        // If the game ended in this round, exit loop.
        if (A.stacksize() == 0) { break; }
    }
}

TEST_CASE("Case 3: Winning or draw.") {
    // Creating 2 players and the game.
    Player A("Alice");
    Player B("Bob");
    Game game(A, B);
    // Play till someone the end of the game.
    game.playAll();
    // If the game ended with a draw.
    if (A.cardesTaken() == B.cardesTaken()) {
        // ---- Testing: Checking who won when there was a draw.
        // ---- Expecting: Should throw exception.
        CHECK_THROWS(game.printWiner());
    }
    // Else if the game ended with someone winning.
    else {
        // ---- Testing: Checking who won when we know for sure someone won.
        // ---- Expecting: Should work.
        CHECK_NOTHROW(game.printWiner());
    }
    // ---- Testing: Checking the last turn and stats after finishing the game.
    // ---- Expecting: Should work.
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("Case 4: Constructors check.") {
    // ---- Testing: Creating a player with no name.
    // ---- Expecting: Should work and give default empty name.
    CHECK_NOTHROW(Player A);
    // Creating 2 players.
    Player B("Alice");
    Player C("Bob");
    // ---- Testing: Creating 2 games with the same players.
    // ---- Expecting: Should throw exception.
    Game game(B, C);
    CHECK_THROWS(Game(B, C));
    // ---- Testing: Creating 2 players with the same name.
    // ---- Expecting: Should work since 2 people can have the same name.
    Player D("John");
    CHECK_NOTHROW(Player("John"));
    // ---- Testing: Creating a game with the same player.
    // ---- Expecting: Should throw exception.
    Player E("Shalev");
    CHECK_THROWS(Game(E,E));
}