/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA6 - Spanning the Gamut (Kruskal’s Algorithm)
*/

#include "FileInput.h"
#include <iostream>
using namespace std;

// main method reads command line argument for input file name
// uses error handling to ensure file name is included
// method calls FileInput readFile class to handle program logic
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Input file not included at argument" << endl;
        return 1;
    }

    FileInput file(argv[1]);
    file.readFile();

    return 0;
}