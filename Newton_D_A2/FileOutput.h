/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA2 - Not So Super Mario Bros.
*/

#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H
#include "Level.h"

#include <string>

// defines FileOutput class
// class includes public constructor and destructor, addToOutput method, and outputGrid method
// class includes private logName string representing the name of the log file
class FileOutput{
    public:
    FileOutput(std::string logInputName);
    virtual ~FileOutput();
    void addToOutput(std::string text);
    void outputGrid(char*** newLevel, int gridN, int roundNum);

    private:
    std::string logName;
};
#endif