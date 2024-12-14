/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA4 - Genetic Palindromes
*/

#ifndef DNASEQ_H
#define DNASEQ_H
#include <cstdlib>
#include <string>
#include "DblList.h"
using namespace std;

// defines DNASeq class
// class includes public constructor and destructor, complement, substring, isGeneticPalindrome, removeFromBack, returnSize, getVal, and printSeq methods
// class includes private sequence BdlList pointer
class DNASeq{
    public:
    DNASeq();
    DNASeq(string seqString);
    virtual ~DNASeq();
    DNASeq complement();
    DNASeq substring(int s, int e);
    bool isGeneticPalindrome();
    bool removeFromBack();
    int returnSize();
    char getVal(int pos);
    string printSeq();

    private:
    DblList<char>* sequence; // pointer to a DBL List object
};

#endif