/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#ifndef MONSTER_H
#define MONSTER_H

#include <string>

// defines Monster class
// class includes public constructor and destructor, screamFight, getScream, and getName methods
// class includes private m_screamPower and m_name
class Monster
{
private:
    int m_screamPower;
    std::string m_name;
public:
    Monster();
    Monster(std::string name, int screamPower);
    virtual ~Monster();
    bool screamFight(Monster otherMonster);
    int getScream();
    std::string getName();
};

#endif