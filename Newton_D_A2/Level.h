/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#ifndef LEVEL_H
#define LEVEL_H

#include <string>

// defines Level class
// class includes public constructor, overloaded constructor and destructor, createLevel method, and fillGrid method
class Level{
    public:
    Level();
    Level(int coins, int nothing, int goomba, int koopa, int mushroom, int dimensions);
    virtual ~Level();
    char** createLevel(char** levelArray, bool isFinal);
    void fillGrid(char** levelArray);

    int gridN;
    int coinsNum;
    int nothingNum;
    int goombaNum;
    int koopaNum;
    int mushroomNum;
    int random_number;
    int random_number2;
};
#endif