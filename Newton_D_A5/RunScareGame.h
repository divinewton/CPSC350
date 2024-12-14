/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#ifndef RUNSCAREGAME_H
#define RUNSCAREGAME_H

#include <string>
#include <iostream>
#include "TournamentTree.h"
#include <vector>
#include <cstring>

// defines RunScareGame class
// class includes public constructor and destructor, overloaded constructor, and runTournament methods
// class includes private m_input, m_output, and m_type string variables
class RunScareGame
{
private:
    std::string m_input;
    std::string m_output;
    std::string m_type;
public:
    RunScareGame();
    RunScareGame(std::string inputFile, std::string outputFile, std::string gameType);
    virtual ~RunScareGame();
    void runTournament(); // starts and completes the game
};

#endif