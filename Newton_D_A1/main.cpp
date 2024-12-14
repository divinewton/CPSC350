/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA1 - Robber Language
*/

#include <iostream>
#include <string>
#include "FileProcessor.h"
using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3) {
        cout << "Input invalid. Please include input (.txt) and output (.html) file names including extension."; // prompts user to include neccesary file names if not included
    }
    string inputFile = argv[1];
    string outputFile = argv[2];

    // create instance of fileProcessor to process input and output files
    FileProcessor fileProcessor;
    fileProcessor.processFile(inputFile, outputFile);
    return 0;
}