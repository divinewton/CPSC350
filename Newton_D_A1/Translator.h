/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA1 - Robber Language
*/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
#include "model.h"

// defines Translator class
// class includes public constructor and destructor, translateEnglishWord and translateEnglishSentence methods
// class includes a private instance of the Model class
class Translator{
  public:
  Translator();
  virtual ~Translator();
  std::string translateEnglishWord(std::string c);
  std::string translateEnglishSentence(std::string x);

  private:
  Model model;
};
#endif