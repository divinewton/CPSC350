/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#include "Level.h"
#include <fstream>
using namespace std;

Level::Level() {

}

// Level constructor takes in ints of coins, nothing, goombas, koopas, and mushroom perportions as well as grid dimensions
// calculates amount of each on grid through converting percents with grid dimensions
Level::Level(int coins, int nothing, int goomba, int koopa, int mushroom, int dimensions){
    gridN = dimensions;
    coinsNum = (dimensions*dimensions)*(coins/100.0);
    nothingNum = (dimensions*dimensions)*(nothing/100.0);
    goombaNum = (dimensions*dimensions)*(goomba/100.0);
    koopaNum = (dimensions*dimensions)*(koopa/100.0);
    mushroomNum = (dimensions*dimensions)*(mushroom/100.0);
    random_number;
    random_number2;
    srand(time(nullptr)); // sets random number generator
}

Level::~Level() {
    
}

// fillGrid method takes in a char** object
// it gets two random numbers and set every spot on the grid to "x"
void Level::fillGrid(char** levelArray){ 
    random_number = rand() % gridN;
    random_number2 = rand() % gridN;
    while(levelArray[random_number][random_number2] != 'x'){ 
        random_number = rand() % gridN;
        random_number2 = rand() % gridN;
    }
}

// createLevel array takes in a char** object and a bool value
// it calls the levelArray method for letter and adds the correct amount of that object to the grid
// returns the filled grid
char** Level::createLevel(char** levelArray, bool isFinal) {
    for (int i = 0; i < gridN; ++i) {
        for (int j = 0; j < gridN; ++j) {
            levelArray[i][j] = 'x';
        }
    }
    for(int k = 0; k < coinsNum; ++k){
        fillGrid(levelArray);
        levelArray[random_number][random_number2] = 'c'; 
    }
    for(int l = 0; l < goombaNum; ++l){
        fillGrid(levelArray);
        levelArray[random_number][random_number2] = 'g';
    }

    for(int l = 0; l < koopaNum; ++l){
        fillGrid(levelArray);
        levelArray[random_number][random_number2] = 'k';
    }

    for(int l = 0; l < mushroomNum; ++l){
        fillGrid(levelArray);
        levelArray[random_number][random_number2] = 'm';
    }

    fillGrid(levelArray);
    levelArray[random_number][random_number2] = 'b';

    if(!isFinal){ // if it's not the final level, adds a warp to grid
    fillGrid(levelArray);
    levelArray[random_number][random_number2] = 'w';
    }
    return levelArray;
}