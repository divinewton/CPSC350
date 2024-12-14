/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA3 - Do You See What I See?
*/

#include "SpeakerView.h"
using namespace std;

// main method creates pointer to SpeakerView class
// calles getDimensions and createStacks to output the results to the terminal
int main(int argc, char** argv){

    SpeakerView* newView = new SpeakerView(argv[1]); // takes argv[1], the name of the input file
    newView->getDimensions();
    newView->createStacks();
    return 0;
}