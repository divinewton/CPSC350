/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA1 - Robber Language
*/

#include <string>
#include <cctype>
#include "Translator.h"
using namespace std;

Translator::Translator() {
}

Translator::~Translator() {
}

// translateEnglishWord takes in a string of a word
// it translates by checking if each letter/character is a vowel, consonant, or punctuation and treating as such
// returns a string of the word translated to Robber Language
string Translator::translateEnglishWord(string c){
    string word;
    string consonants = "bcdfghjklmnpqrstvwxyz";

    for (int i = 0; i < c.size(); i++) {
        char letter = c[i];
        if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u') {
            word += model.translateSingleVowel(letter); // if letter is a vowel, uses translateSingleVowel method
        }
        else if (consonants.find(tolower(letter)) < consonants.length()) {
            word += model.translateSingleConsonant(letter); // if letter is a consonant, uses translateSingleConsonant
        }
        else {
            word += letter; // if character is punctuation, adds directly to word
        }
    }
    return word;
}

// translateEnglishSentence takes in aa string of a sentence
// it translates by iterating through each letter and seperating into translatable words
// returns a string of the word translated to Robber Language
string Translator::translateEnglishSentence(string x) {
    string sentence;
    string word;

    for (int i = 0; i < x.size(); i++) {
        char letter = x[i];
        if (letter == ' ') {
            if (!word.empty()) {
                sentence += translateEnglishWord(word); // sends full word to translateEnglishWord once a space is reached
                word.clear();
            }
            sentence += ' '; // adds a space after each word to the new translated string
        } else {
            word += letter;
        }
    }
    if (!word.empty()) {
        sentence += translateEnglishWord(word); // handles the last word of the initial string after the last space
    }
    return sentence;
}