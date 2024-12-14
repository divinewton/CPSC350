#include "Person.h"

Person::Person(){
    m_name = "unknown";
}

Person::Person(string name){
    m_name = name;
}

Person::~Person(){
}

string Person::getName(){
    return m_name;
}

void Person::setName(string name){
    m_name = name;
}