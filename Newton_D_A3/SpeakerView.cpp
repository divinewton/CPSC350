/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA3 - Do You See What I See?
*/

#include "SpeakerView.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include "MonoStack.h"
using namespace std;

SpeakerView::SpeakerView(string fileName) {
    file = fileName;
    rows = 0;
    cols = 0;
    MonoStack<double>* columnStacks;
}

SpeakerView::~SpeakerView() {
    delete columnStacks;
}

// getDimensions method iterates through the input file and sets rows and cols ints to the correct numbers
void SpeakerView::getDimensions() {
    ifstream inFile(file);
    if (inFile.is_open()) {
        string line;
        // emsures to skip the first line
        bool firstLine = true;
        while (getline(inFile, line)) { 
            if (firstLine) {
                firstLine = false;
                continue;
            }
            rows++;
        }
        inFile.close();
        ifstream inFile(file);
        // skips the first line
        string extra;
        getline(inFile, extra);
        string newLine;
        getline(inFile, newLine);
        int currentCols = 1;
        // loops to find the number of columns in the second row
        for (int i = 0; i < newLine.length(); i++) {
            if (newLine[i] == ' ') {
                currentCols++;
            }
        }
        cols = currentCols;
        rows = rows - 1;
    } else { // if the file could not be opened
        cout << "Failed to open file. Ensure correct file name it included in command line" << endl;
    }
}

// createStacks method loops through the input file to add each column to a stack and output the results
// it reuses the same stack for each column, as it will always be the same size
void SpeakerView::createStacks() {
    columnStacks = new MonoStack<double>(cols, 'd'); // instantiates the stack object
    ifstream inFile(file);
    if (!inFile.is_open()) { // ensures the file can open
        cout << "Failed to open file. Ensure correct file name is included in command line" << endl;
        return;
    }

    // loops through each column
    for (int i = 0; i < cols; ++i) {
        ifstream inFile(file);
        // read the column into the stack
        double value;
        double skipped;
        int lineNum = 0;
        string firstLine;
        getline(inFile, firstLine); // skips the first line
        for (int j = 0; j < rows; ++j) { // iterates row by row
            if (!lineNum == 0) { // skips the nessesary spaces depending on the column
                for (int t = 0; t < cols - (i + 1); ++t) {
                    inFile >> skipped;
                }
            }
            if (!i == 0) { // skips the nessesary rows each time
                for (int skip = 0; skip < i; ++skip) {
                    inFile >> skipped;
                }
            }
            // adds the resulting double to the stack
            inFile >> value;
            columnStacks->push(value);
            lineNum++;
        }
        inFile.close();

        // calls print result to output the results of that column, then empties the stack
        printResults(columnStacks, i);
        while (!columnStacks->isEmpty()) {
            columnStacks->pop();
        }
    }
}

// printResults method takes in the stack and number of columns
// outputs the results for the column including each hight that will be able to see
void SpeakerView::printResults(MonoStack<double>* stack, int numCol) {
    cout << "In column " + to_string(numCol) + " there are " + to_string(stack->size()) + " that can see. Their heights are: " << flush;
        while (!stack->isEmpty()) {
            while (stack->size() > 1) { // ensures comma is not added to the last value
                cout << stack->pop() << ", " << flush;
            }
            cout << stack->pop() << " inches." << endl;
        }
}