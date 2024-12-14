/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA6 - Spanning the Gamut (Kruskal’s Algorithm)
*/

#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <string>
#include <fstream>

// defines FileInput class
// class includes public constructor and destructor, and readFile method
// class includes private file string variable
class FileInput {
public:
    FileInput(const std::string& filename);
    FileInput();
    ~FileInput();
    void readFile();

private:
    std::string file; // variable for input file name
};

#endif