/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#include "Monster.h"

// default constructor
Monster::Monster() {
    
}

// overloaded constructor
// includes and sets name and screamPower variables
Monster::Monster(std::string name, int screamPower) {
    m_name = name;
    m_screamPower = screamPower;
}

// destructor
Monster::~Monster() {

}

// screamFight method calculates the winner of a fight with this and another monster
// method returns the a bool representing the winner
bool Monster::screamFight(Monster otherMonster) {
    bool winner = false;
    if (this -> getScream() > otherMonster.getScream()) {
        winner = true;
    }

    return winner;
}

// getScream method returns this monster's screamPower
int Monster::getScream() {
    return m_screamPower;
}

// getName method returns this monster's name
std::string Monster::getName() {
    return m_name;
}

