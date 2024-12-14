/*
Name: Divi Newton
Student ID: 2440117
Email: dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA1 - Robber Language
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include "Translator.h"

// defines Translator class
// class includes public constructor and destructor, processFile method
// class includes private formatHtml method and a private instance of the Translator class
class FileProcessor{
  public:
  FileProcessor();
  virtual ~FileProcessor();
  void processFile(std::string c, std::string x);

  private:
  std::string formatHtml(std::string english, std::string robber);
  Translator translator;
};
#endif