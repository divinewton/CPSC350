/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA4 - Genetic Palindromes
*/

#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H
#include <cstdlib>
#include <string>
#include "DNASeq.h"
using namespace std;

// defines PalindromeFinder class
// class includes public constructor and destructor, printProgram, printPalindrome, and isValid methods
// class includes private dnaSequence DNASeq pointer
class PalindromeFinder{
    public:
    PalindromeFinder(DNASeq* dnaSequence);
    virtual ~PalindromeFinder();
    void printProgram();
    void printPalindrome(DNASeq* dnaSequence);
    bool isValid(DNASeq* dnaSequence);

    private:
    DNASeq* dnaSequence; // pointer to a DNASeq object
};

#endif