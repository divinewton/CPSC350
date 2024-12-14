/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA6 - Spanning the Gamut (Kruskal’s Algorithm)
*/

#include "FileInput.h"
#include "WGraph.h"
#include <fstream>
#include <iostream>

FileInput::FileInput() {
    
}

// overloaded constructor
FileInput::FileInput(const std::string& filename) {
    file = filename;
}

// destructor
FileInput::~FileInput() {

}

// readFile method reads the input file using the commentline argument
// method calls the WGraph class and adds the edges to the adjacency matrix
// prints the resulting MST and cost to the terminal
void FileInput::readFile() {
    ifstream infile(file);
    if (!infile) { // error handling for opening input file
        cerr << "Error opening input file" << endl;
    }
    int size;
    infile >> size; // saves size to variable

    WGraph graph(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) { // loops through weight values and adds to the graph
            double weight;
            infile >> weight;
            if (weight != 0.0) {
                graph.addEdge(i, j, weight);
            }
        }
    }
    string end;
    infile >> end;
    if (end != "END") { // error handling for incorrect input file formatting
        cerr << "Error: Expected 'END' at the end of the file." << endl;
    }
    double mstCost = graph.computeMST(); // calls method compute the MST of the weighted graph
    cout << "The MST Cost is: " << mstCost << endl;
    graph.printMST(); // prints the resulting MST to the console
}