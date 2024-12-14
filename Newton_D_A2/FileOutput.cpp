/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#include <fstream>
#include "FileOutput.h"
#include "Level.h"
using namespace std;

FileOutput::FileOutput(string logInputName) {
    logName = logInputName;
}

FileOutput::~FileOutput() {
}

// addToOutput takes in a string of text and returns nothing
// opens the output file, adds the text, and closes it
void FileOutput::addToOutput(string text) {
    ofstream outputFile;
    outputFile.open(logName, ios::app);
    outputFile << text << flush;
    outputFile.close();
}

// outputGrid takes in a level array, int grid size, and int round number
// it loops through the current round's grid and prints it using the addToOutput method
void FileOutput::outputGrid(char*** newLevel, int gridN, int roundNum) {
    for (int i = 0; i < gridN; ++i) {
        string line;
        for (int j = 0; j < gridN; ++j) {
            line += newLevel[roundNum][i][j];
            line += ' ';
        }
        addToOutput(line + "\n");
    }
    addToOutput("==========\n"); // formats space after grid
}