/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA1 - Robber Language
*/

#ifndef MODEL_H
#define MODEL_H

#include <string>

// defines Model class
// class includes public constructor and destructor, translateSingleConsonant and translateSingleVowel methods
class Model{
  public:
  Model();
  virtual ~Model();
  std::string translateSingleConsonant(char c);
  std::string translateSingleVowel(char x);
};
#endif