/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#include "World.h"

int main(int argc, char** argv){

    // creates a world pointer and calls the startGame method to begin the simulation
    World* newGame = new World(argv[1], argv[2]);
    newGame->startGame();

    delete newGame; // deletes World pointer when complete
}