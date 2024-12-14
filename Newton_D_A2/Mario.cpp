/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#include "Mario.h"
#include "World.h"
#include "Level.h"
#include <cstdlib>
using namespace std;

// Mario constructor takes in an int of lives (taken from spec.txt file) and a World pointer
// it sets lives, world, coins, and powerLevel to the correct amounts
// sets mario's default position to (0, 0)
Mario::Mario(int lives, World* world) : lives(lives), world(world), coins(0), powerLevel(0) {
    position[0] = 0;
    position[1] = 0;
}

Mario::~Mario() {
}

// setPowerLevel method takes in a new level and sets powerLevel to that
void Mario::setPowerLevel(int newLevel) {
    powerLevel = newLevel;
}

// getPowerLevel method returns mario's powerLevel in int form
int Mario::getPowerLevel() {
    return Mario::powerLevel;
}

// setCoins method takes in a new coin amount and adds that to the current amount
// if coins is over 20, it gives mario another life and sets coins to 0
void Mario::setCoins(int newCoins) {
    coins += newCoins;
    if (coins > 20) {
        coins = 0;
        ++lives;
    }
}

// getCoins method returns mario's amount of current coins in int form
int Mario::getCoins() {
    return Mario::coins;
}

// fightGoomba method returns true or false if mario won or lost to the Goomba
// it uses probability of 80% to determine outcome
// if mario looses, it decreases the power level
bool Mario::fightGoomba() {
    int probability = rand() % 100;
    if (probability <= 80) {
        return true;
    } else {
        setPowerLevel(getPowerLevel() - 1);
        world->fightAgain = 'g'; // sets fightAgain to "g" for Goomba
        return false;
    }
}

// fightKoopa method returns true or false if mario won or lost to the Koopa
// it uses probability of 65% to determine outcome
// if mario looses, it decreases the power level
bool Mario::fightKoopa() {
    int probability = rand() % 100;
    if (probability <= 65) {
        return true;
    } else {
        setPowerLevel(getPowerLevel() - 1);
        world->fightAgain = 'k'; // sets fightAgain to "k" for Koopa
        return false;
    }
}

// fightBoss method returns true or false if mario won or lost to the level boss
// it uses probability of 50% to determine outcome
// if mario looses, it decreases the power level by 2
bool Mario::fightBoss() {
    int probability = rand() % 100;
    if (probability <= 50) {
        return true;
    } else {
        setPowerLevel(getPowerLevel() - 2);
        world->fightAgain = 'b'; // sets fightAgain to "b" for boss
        return false;
    }
}

// addMushroom method increases mario's power level if it's nto already 2
void Mario::addMushroom() {
    if (Mario::getPowerLevel() < 2) {
        setPowerLevel(getPowerLevel() + 1);
    }
}

// getPosition returns an array of mario's x and y coordinates
int* Mario::getPosition() {
    return position;
}

// getLives returns mario's remaining lives in int form
int Mario::getLives() {
    return lives;
}

// setLives takes in a new number of remaining lives and sets lives to that amount
void Mario::setLives(int newLives) {
    lives = newLives;
}

// moveOn method produces random numbers between 0 and 4
// it returns a string representing the movement direction
string Mario::moveOn() {
    int newPos = rand() % 4;
    if (newPos == 0) {
        return "UP";
    } else if (newPos == 1) {
        return "DOWN";
    } else if (newPos == 2) {
        return "LEFT";
    } else if (newPos == 3) {
        return "RIGHT";
    }
}

// newPosition method takes in the string direction
// for each direction it sets that position in the grid to "H" for mario
// also sets mario's position variable to the new position
void Mario::newPosition(string direction) {
    int row = position[0];
    int col = position[1];

    if (direction == "UP") {
        if (row == 0) {
            // if mario's at the top row, move to the bottom instead
            world->setCurrentChar(world->levels[world->roundNum][world->gridN - 1][col]);
            world->levels[world->roundNum][world->gridN - 1][col] = 'H';
            row = world->gridN - 1;
        } else {
            world->setCurrentChar(world->levels[world->roundNum][row - 1][col]);
            world->levels[world->roundNum][row - 1][col] = 'H';
            row = row - 1;
        }
    } else if (direction == "DOWN") {
        // if mario's at the bottom row, move to the top instead
        if (row == world->gridN - 1) {
            world->setCurrentChar(world->levels[world->roundNum][0][col]);
            world->levels[world->roundNum][0][col] = 'H';
            row = 0;
        } else {
            world->setCurrentChar(world->levels[world->roundNum][row + 1][col]);
            world->levels[world->roundNum][row + 1][col] = 'H';
            row = row + 1;
        }
    } else if (direction == "LEFT") {
        // if mario's at the far left already, move to the right side
        if (col == 0) {
            world->setCurrentChar(world->levels[world->roundNum][row][world->gridN - 1]);
            world->levels[world->roundNum][row][world->gridN - 1] = 'H';
            col = world->gridN - 1;
        } else {
            world->setCurrentChar(world->levels[world->roundNum][row][col - 1]);
            world->levels[world->roundNum][row][col - 1] = 'H';
            col = col - 1;
        }
    } else if (direction == "RIGHT") {
        // if mario's at the far right already, move to the left side
        if (col == world->gridN - 1) {
            world->setCurrentChar(world->levels[world->roundNum][row][0]);
            world->levels[world->roundNum][row][0] = 'H';
            col = 0;
        } else {
            world->setCurrentChar(world->levels[world->roundNum][row][col + 1]);
            world->levels[world->roundNum][row][col + 1] = 'H';
            col = col + 1;
        }
    } else if (direction == "random") {
        // uses random for placing mario at the start of each round
        bool updated = false;
        if (updated == false) { // ensures mario's position is only added once
            for (int i = 0; i < world->gridN; ++i) {
                for (int j = 0; j < world->gridN; ++j) {
                    if (world->levels[world->roundNum][i][j] == 'x') { // finds the first open space in the grid and adds "H"
                        world->setCurrentChar(world->levels[world->roundNum][i][j]);
                        world->levels[world->roundNum][i][j] = 'H';
                        row = i;
                        col = j;
                        updated = true;
                        break;
                    }
                }
                if (updated == true) {
                    break;
                }
            }
        }
    }
    // updates mario's position variable to new location
    position[0] = row;
    position[1] = col;
}