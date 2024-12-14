/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#include "RunScareGame.h"
#include <iostream>
#include <fstream>
using namespace std;

// main method ensures correct arguments are included
// a new game is started, based on the nessesary components of input and output file names and game type
int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Incorrect usage. Include " << argv[0] << " inputFile outputFile gameType." << endl;
        return 1;
    }

    if (strcmp(argv[3], "single") != 0 && strcmp(argv[3], "double") != 0) {
        cout << "Incorrect game type. Use either single or double." << endl;
        return 1;
    }

    RunScareGame* newGame = new RunScareGame(argv[1], argv[2], argv[3]); // creates a RunScareGame object with correct arguments
    newGame->runTournament(); // used to complete the game and output file

    delete newGame;
    return 0;
}