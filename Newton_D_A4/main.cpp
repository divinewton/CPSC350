/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA4 - Genetic Palindromes
*/

#include <iostream>
#include <fstream>
#include <string>
#include "DblList.h"
#include "PalindromeFinder.h"
#include "DNASeq.h"
using namespace std;

// main method ensures correct fileName argument was included and it can open
// reads the file, and for each line it makes a DNASeq pointer and calls the PalindromeFinder's printProgram method to output to terminal
// each line is read and results are outputed, until the END line is reached
int main(int argc, char** argv){
    if (argc != 2) { // ensures the file name was included
        cout << "File name must be included. Please try again." << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);
    if (!file.is_open()) { // ensures the file can be opened and read
        cout << "Failed to open " << filename << " . Please try again." << endl;
        return 1;
    }

    string newSeq;
    getline(file, newSeq); // reads the first line to a string
    while (newSeq != "END") {
        DNASeq* dnaSequence = new DNASeq(newSeq); // creates dnaSequence with the string
        PalindromeFinder palindromeFinder(dnaSequence); // creates palindromeFiner with the DNASeq
        palindromeFinder.printProgram(); // prints results to the terminal
        getline(file, newSeq); // reads the next line
    }
    file.close(); // closes the input file at the end
    return 0;
}