/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA1 - Robber Language
*/

#include "Model.h"
using namespace std;

Model::Model() {
}

Model::~Model() {
}

// translateSingleConsonant takes in a consonant
// it translates by adding the letter, than an 'o', than the letter again to a new string, and returning it
string Model::translateSingleConsonant(char c){
    string consonant;
    consonant += c;
    consonant += 'o';
    consonant += tolower(c); // ensures second instance of the letter is lowercase
    return consonant;
}

// translateSingleVowel takes in a vowel
// it translates by adding the letter to a new string, and returning it
string Model::translateSingleVowel(char x){
    string vowel;
    vowel += x;
    return vowel;
}