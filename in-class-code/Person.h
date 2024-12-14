#ifndef PERSON_H //header guard - prevent C++ header files from being included multiple times
#define PERSON_H

#include <string>
using namespace std; //importing standard library into the current namespace

class Person{
    public:
        Person(); //default constructor
        Person(string name); //overloaded constructor
        virtual ~Person(); //destructor
        string getName(); //accessor
        void setName(string name); //mutator
    private:
        string m_name; //member variable
};

#endif
