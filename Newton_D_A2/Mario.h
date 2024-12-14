/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#ifndef MARIO_H
#define MARIO_H

#include <string>

// defines a World class object within Mario for interactions
class World;

// defines Mario class
// class includes public constructor and destructor, as well as nessesary methods and variables
// class includes a private instance of the world class in order to interact with it in real time
class Mario{
    public:
    Mario(int lives, World* world);
    virtual ~Mario();
    bool fightGoomba();
    bool fightKoopa();
    bool fightBoss();
    void setCoins(int newCoins);
    int getCoins();
    void setPowerLevel(int newLevel);
    int getPowerLevel();
    void addMushroom();
    void newPosition(std::string direction);
    int* getPosition();
    int getLives();
    void setLives(int newLives);
    std::string moveOn();

    private:
    int coins;
    int lives;
    int powerLevel;
    int position[2];
    World* world;
};
#endif