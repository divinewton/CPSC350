/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA4 - Genetic Palindromes
*/

#include <cstdlib>
#include <string>
#include <iostream>
#include "DNASeq.h"
#include "PalindromeFinder.h"
using namespace std;

// constructor
PalindromeFinder::PalindromeFinder(DNASeq* newDnaSequence) {
    dnaSequence = newDnaSequence;
}

// destructor
PalindromeFinder::~PalindromeFinder() {

}

// printProgram method calls printPalindrome then finds each substring palindrome and prints it
void PalindromeFinder::printProgram() {
    printPalindrome(dnaSequence); // used to print the initial sequence with results
    if (isValid(dnaSequence)) {
        int seqLength = dnaSequence->returnSize();
        for (int length = 5; length < seqLength; length++) { // loops between 5 and sequence length
            for (int start = 0; start <= seqLength - length; start++) { // loops between start and max length
                DNASeq subSeq = dnaSequence->substring(start, start + length); // finds if current substring is a palindrome
                if (subSeq.isGeneticPalindrome()) {
                    cout << "   Substring " << subSeq.printSeq() << " - Genetic Palindrome" << endl;
                }
            }
        }
    }
}

// printPalindrome method prints the sequence and whether it is a palindrome to the terminal
void PalindromeFinder::printPalindrome(DNASeq* dna) {
    cout << dna->printSeq() << " - " << flush;
    if (isValid(dnaSequence)) { // checks it is valid
        if (dna->isGeneticPalindrome()) {
            cout << "Genetic Palindrome" << endl;
        } else {
            cout << "Not a Genetic Palindrome" << endl;
        }
    } else {
        cout << "INVALID" << endl;
    }
}

// isValid method ensures each letter is an A, C, T, or G
bool PalindromeFinder::isValid(DNASeq* dnaSequence) {
    for (int i = 0; i < dnaSequence->returnSize(); i++) {
        if (dnaSequence->getVal(i) != 'A' && dnaSequence->getVal(i) != 'C' && dnaSequence->getVal(i) != 'T' && dnaSequence->getVal(i) != 'G') {
            return false;
        }
    }
    return true;
}