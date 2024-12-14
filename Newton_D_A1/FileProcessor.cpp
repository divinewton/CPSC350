/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA1 - Robber Language
*/

#include "FileProcessor.h"
#include <fstream>
using namespace std;

FileProcessor::FileProcessor() {
}

FileProcessor::~FileProcessor() {
}

// processFile takes in strings representing the input tile's title and the output file's title
// it reads the input file into a string and processes the translation
// it then creates a new HTML file containing the initial text as well as the translation
void FileProcessor::processFile(string input, string output) {
    string contentFromFile;
    string inputContents;
    ifstream readFile(input);
    while (getline(readFile, inputContents)) { // uses fstream to read the file line by line into inputContents
        contentFromFile += inputContents + "\n"; // adds each line from inputContents to contentFromFile string
        inputContents.clear(); 
    }

    string line;
    string english;
    string robber;

    // iterates through each letter and creates a string, line by line, of the initial text (english) and the translated text (robber)
    // new strings 'english' and 'robber' include basice line by line html markup code
    for (int i = 0; i < contentFromFile.size(); i++) {
        char letter = contentFromFile[i];
        if (letter == '\n') {
            if (!line.empty()) {
                english += "<p><b>" + line + "</b><br></p>\n";
                robber += "<p><i>" + translator.translateEnglishSentence(line) + "</i><br></p>\n"; // uses previous methods to translate
                line.clear(); // resets to new empty line after line of text is translated
            }
        } else {
            line += letter; // adds each letter to line string to be translated
        }
    }
    if (!line.empty()) { // handles translation of the last line of the file (after the last newline character)
        english += "<p><b>" + line + "</b><br></p>\n";
        robber += "<p><i>" + translator.translateEnglishSentence(line) + "</i><br></p>\n";    
    }

    // uses formatHTML to format the new HTML file with english and robber translation strings
    string outputText = formatHtml(english, robber);
    ofstream newFile(output); // creates HTML file from provided name
    newFile << outputText;
    newFile.close();
}

// formatHTML takes in a string of initial english and a string of robber translation
// both strings already contain HTML formatting for each line, but not the full HTML file structure
// returns a string of the entire HTML file including all structure needed
string FileProcessor::formatHtml(string english, string robber) {
    string output;
    output += "<!DOCTYPE html>\n<html>\n<head>\n<title>English to Robber Translation</title>\n</head>\n<body>\n";
    output += english;
    output += "<p><b></b><br></p>\n";
    output += robber;
    output += "<p><i></i><br></p>\n</body>\n</html>";
    return output;
}