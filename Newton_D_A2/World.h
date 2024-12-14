/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#ifndef WORLD_H
#define WORLD_H

#include <string>
#include "FileOutput.h"
#include "Mario.h"
#include "Level.h"
#include <fstream>

// defines a Mario class object within World for interactions
class Mario;

// defines World class
// class includes public constructor, overloaded constructor, and destructor, as well as nessesary methods and variables
// class includes pointers to FileOutput, Mario, and Level classes in order to interact in real time
class World{
    public:
    World();
    World(std::string specFile, std::string logFile);
    virtual ~World();
    void createWorld(std::string fileName);
    void startGame();
    void setMarioWon(bool result);
    void emptyLocation();
    void emptyLocation(int* oldPosition);
    void setCurrentChar(char newChar);

    FileOutput* outputter;
    Mario* mario;
    Level* newLevel;

    int levelsL;
    int gridN;
    int lives;
    int coins;
    int nothing;
    int goombas;
    int koopas;
    int mushrooms;
    bool marioWon;
    int roundNum;
    char currentChar;
    char fightAgain;
    int enemyCount;
    char*** levels;

    private:
    int numTurns;
    char keepChar;
};
#endif