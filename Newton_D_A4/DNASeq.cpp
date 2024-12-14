/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA4 - Genetic Palindromes
*/

#include <cstdlib>
#include <string>
#include "DblList.h"
#include "DNASeq.h"
using namespace std;

// constructor
DNASeq::DNASeq() {
    sequence = new DblList<char>();
}

// overloaded constructor to create sequence from a string
DNASeq::DNASeq(string seqString) {
    sequence = new DblList<char>();
    for (int i = 0; i < seqString.length(); i++) { // loops to add each char to the list
        sequence->addBack(seqString[i]);
    }
}

// destructor
DNASeq::~DNASeq() {
    delete sequence;
}

// complement method gets each value and changes it to the correct alternate value before adding it to the new list
// returns a new DNASeq object of the complement
DNASeq DNASeq::complement() {
    string compString;
    for (int i = 0; i < sequence->getSize(); i++) {
        char data = sequence->get(i);
        if (data == 'A') {
            data = 'T';
        } else if (data == 'T') {
            data = 'A';
        } else if (data == 'C') {
            data = 'G';
        } else if (data == 'G') {
            data = 'C';
        }
        compString += data;
    }
    DNASeq complement(compString);
    return complement;
}

// substring method takes in two numbers, and outputs a DNASeq object containing the letters between those two positions
DNASeq DNASeq::substring(int s, int e) {
    string substring;
    for (int  i = s; i < e; i++) { // loops between these two values
        substring += sequence->get(i);
    }
    DNASeq sub(substring);
    return sub;
}

// isGeneticPalindrome method checks if a DNASeq is a genetic palendrome by compairing it to the backwards complement
bool DNASeq::isGeneticPalindrome() {
    DNASeq complementSeq = complement();
    for (int i = 0; i < sequence->getSize(); i++) {
        if (sequence->get(i) != complementSeq.getVal(complementSeq.returnSize() - 1 - i)) { // checks if not equal
            return false;
        }
    }
    return true;
}

// removeFromBack method calls the DblList removeBack() method
bool DNASeq::removeFromBack() {
    sequence->removeBack();
}

// returnSize method calls the DblList getSize() method
int DNASeq::returnSize() {
    return sequence->getSize();
}

// printSeq method loops through the DNASeq and prints each value to the terminal
string DNASeq::printSeq() {
    string printResults;
    for (int i = 0; i < sequence->getSize(); i++) {
        printResults += sequence->get(i);
    }
    return printResults;
}

// getVal method calls the DblList get() method to return a value in the list
char DNASeq::getVal(int pos) {
    return sequence->get(pos);
}