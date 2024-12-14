/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#include "World.h"
#include "Level.h"
#include "FileOutput.h"
#include "Mario.h"
#include <fstream>
using namespace std;

// World destructor deletes mario, level, and outputter pointers and each level of the grid
World::~World() {
    delete mario;
    delete newLevel;
    delete outputter;

    for (int i = 0; i < levelsL; ++i) {
        for (int j = 0; j < gridN; ++j) {
            delete[] levels[i][j];
        }
        delete[] levels[i];
    }
    delete[] levels;
}

// World constructor takes in strings of spec file and log file names
// it first reads variables from the input file and sets them to variables
// sets World variables and creates FileOutput, Level, and Mario pointers
World::World(string specFile, string logFile) {  // sourced from Tom
    int* inputFile = new int[8];
    string contentFromFile;
    int iterate = -1;
    ifstream readFile(specFile);

    if(readFile.is_open()){
        while(getline(readFile, contentFromFile)){
            inputFile[++iterate] = stoi(contentFromFile);
        }
    }
    // sets each variable from the spec file to a local variable
    levelsL = inputFile[0];
    gridN = inputFile[1];
    lives = inputFile[2];
    coins = inputFile[3];
    nothing = inputFile[4];
    goombas = inputFile[5];
    koopas = inputFile[6];
    mushrooms = inputFile[7];
    delete[] inputFile; // deletes inputFile to save memory

    outputter = new FileOutput(logFile); // object for outputting to log file
    newLevel = new Level(coins, nothing, goombas, koopas, mushrooms, gridN); // level pointer to prepresent the game grid
    mario = new Mario(lives, this); //represents mario instance for interactions
    
    // makes an array with the correct amount of empty levels
    levels = new char**[levelsL];
    for (int i = 0; i < levelsL; ++i) {
        levels[i] = new char*[gridN];
        for (int j = 0; j < gridN; ++j) {
            levels[i][j] = new char[gridN];
        }
    }

    // fills each level 2d array with characters for each object (coin, mushroom, enemy, etc)
    bool isFinal = false;
    for (int i = 0; i < levelsL; ++i) {
        if (i == (levelsL - 1)) {
            isFinal = true;
        }
        newLevel->createLevel(levels[i], isFinal); // calls createLevel method to fill levels
    }
    // sets variables to default values
    marioWon = NULL;
    roundNum = 0;
    numTurns = 0;
    fightAgain = 'x';
    enemyCount = 0;
    keepChar = 'x';
}

// startGame method contains the main game loop to complete all tasks for the game
// calls other world and mario methods in order to move mario around the grid and interact with objects
void World::startGame() {
    bool activeGame = true;
    char moveOn;
    // outputs each level to the log file
    for (int i = 0; i < levelsL; ++i) {
        outputter->outputGrid(levels, gridN, i);
    }
    mario->newPosition("random"); // sets mario's initial position randomly
    outputter->addToOutput("Mario is starting in position: (" + to_string(mario->getPosition()[0]) + ", " + to_string(mario->getPosition()[1]) + ")");
    outputter->addToOutput("\n==========\n");

    // main game loop
    // only runs when activeaGame is set to true
    while (activeGame) {
        outputter->outputGrid(levels, gridN, roundNum);
        outputter->addToOutput("Level: " + to_string(roundNum + 1) + ". ");
        outputter->addToOutput("Mario is at position: (" + to_string(mario->getPosition()[0]) + ", " + to_string(mario->getPosition()[1]) + "). ");
        outputter->addToOutput("Mario is at power level " + to_string(mario->getPowerLevel()) + ". ");

        int* oldPosition = mario->getPosition(); // mario's position at the start of a turn is saved here

        // checks if mario needs to fight an enemy again (decided in the last turn is lost to enemy)
        if (fightAgain == 'g') { // if fighting goomba
            currentChar == 'g';
            fightAgain == 'x';
        } else if (fightAgain == 'k') { // if fighting koopa
            currentChar == 'k';
            fightAgain == 'x';
        } else if (fightAgain == 'b') { // if fighting level boss
            currentChar == 'b';
            fightAgain == 'x';
        }

        // checks what object is present in mario's current position and interacts accordingly
        if (currentChar == 'm') { // if the position contains a mushroom
            mario->addMushroom();
            outputter->addToOutput("Mario ate a mushroom. ");
            moveOn = 'y'; // ensures move forward for next turn
        } else if (currentChar == 'c') { // if the position contains a coin
            mario->setCoins(1);
            outputter->addToOutput("Mario collected a coin. ");
            moveOn = 'y'; // ensures move forward next turn
        } else if (currentChar == 'g') { // if the position contains a goomba
            if (mario->fightGoomba()) {
                outputter->addToOutput("Mario encountered a Goomba and won. ");
                moveOn = 'y';
                keepChar = 'g'; // maintains goomba position after turn
                enemyCount += 1;
            } else {
                outputter->addToOutput("Mario encountered a Goomba and lost. ");
                moveOn = 'n'; // if lost, mario stays in position for next turn
            }
        } else if (currentChar == 'k') { // if the position contains a koopa
            if (mario->fightKoopa()) {
                outputter->addToOutput("Mario encountered a Koopa and won. ");
                moveOn = 'y';
                keepChar = 'k'; // maintains koopa position after turn
                enemyCount += 1;
            } else {
                outputter->addToOutput("Mario encountered a Koopa and lost. ");
                moveOn = 'n'; // if lost, mario stays in position for next turn
            }
        } else if (currentChar == 'b') { // if the position contains the level boss
            if (mario->fightBoss()) {
                outputter->addToOutput("Mario encountered the level boss and won. ");
                moveOn = 'l'; // ensures move to next level if mario won
                enemyCount += 1;
            } else {
                outputter->addToOutput("Mario encountered the level boss and lost. ");
                moveOn = 'n'; // if lost, mario stays in position for next turn
            }
        } else if (currentChar == 'w') { // if the position contains a warp
            outputter->addToOutput("Mario warped and bypassed the level boss. ");
            moveOn = 'l'; // mario will move to next level
        } else { // if position is empty
            outputter->addToOutput("Mario visited an empty space. ");
            moveOn = 'y'; // mario will move again at next turn
        }

        // checks mario's power level each round to ensure didn't loose
        if (mario->getPowerLevel() < 0) { 
            if (mario->getLives() > (mario->getPowerLevel() * -1)) { // if power level is below 0 but still has lives, change lives and power level
                mario->setLives(mario->getLives() + mario->getPowerLevel());
                mario->setPowerLevel(0);
                enemyCount += 0;
            } else { // if no more lives and low power level, mario looses
                activeGame = false;
                outputter->addToOutput("\n\nWE LOST THE GAME! :(\n");
                break;
            }
        }

        // check enemy fight count and gives extra life when nessesary
        if (enemyCount >= 7) {
            mario->setLives(mario->getLives() + 1);
            outputter->addToOutput("Mario gained a life from defeating 7 enemies in one life. ");
            enemyCount = 0;
        }

        // outputs end of turn stats of remaining lives and coins
        outputter->addToOutput("Mario has " + to_string(mario->getLives()) + " lives left. ");
        outputter->addToOutput("Mario has " + to_string(mario->getCoins()) + " coins. ");

        // moves mario to next position if nessesary
        if (moveOn == 'y') { // if moving in the same grid
            string direction = mario->moveOn(); // determines direction of mario's move
            outputter->addToOutput("Mario will move " + direction + ".");
            outputter->addToOutput("\n==========\n");
            // ensures goomba or koopa stay in their positions following the turn
            if (keepChar == 'g') {
                levels[roundNum][oldPosition[0]][oldPosition[1]] = 'g';
                keepChar = 'x';
            } else if (keepChar == 'k') {
                levels[roundNum][oldPosition[0]][oldPosition[1]] = 'k';
                keepChar = 'x';
            } else {
                emptyLocation(oldPosition); // empties mario's old position
            }
            mario->newPosition(direction);
        } else if (moveOn == 'l') { // if moving to the next level
            ++roundNum; // goes to the next level
            if (roundNum >= levelsL) { // if last level, mario won
                outputter->addToOutput("\n\nWE WON THE GAME! :)\n");
                activeGame = false;
                break;
            } else {
                outputter->addToOutput("Mario will move to the next round. ");
                outputter->addToOutput("\n==========\n");
                mario->newPosition("random");
            }
        } else if (moveOn == 'n') { // if staying in the same position
            outputter->addToOutput("Mario will say put. ");
            outputter->addToOutput("\n==========\n");
        }
        numTurns ++; // goes to next turn
    }
    outputter->addToOutput("Mario took " + to_string(numTurns) + " turns this game."); // outputs ending stats
}

// setMarioWon method sets the result of the game to mario winning and ends the game
void World::setMarioWon(bool result) {
    marioWon = result;
}

// emptyLocation method empties an imputted position by setting it to "x"
void World::emptyLocation() {
    int* position = mario->getPosition();
    levels[roundNum][position[0]][position[1]] = 'x';
}
void World::emptyLocation(int* oldPosition) {
    int* position = oldPosition;
    levels[roundNum][position[0]][position[1]] = 'x';
}

// setCurrentChat method sets the object mario is insteracting with to the correct one. 
// method is called from the mario class
void World::setCurrentChar(char newChar) {
    currentChar = newChar;
}