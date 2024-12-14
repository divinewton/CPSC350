/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA3 - Do You See What I See?
*/

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include <cstdlib>
#include <string>
#include "MonoStack.h"
using namespace std;

// defines SpeakerView class
// class includes public constructor and destructor, getDimensions, createStacks, and printResults methods
// class includes private rows, cols, file, and columnStacks stack
class SpeakerView{
    public:
    SpeakerView(string fileName);
    virtual ~SpeakerView();
    void getDimensions();
    void createStacks();
    void printResults(MonoStack<double>* stack, int numCol);

    private:
    int rows;
    int cols;
    string file;
    MonoStack<double>* columnStacks; // pointer to MonoStack object
};

#endif