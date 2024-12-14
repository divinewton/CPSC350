/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#ifndef TOURNAMENTNODE_H
#define TOURNAMENTNODE_H

#include "Monster.h"
#include <iostream>
#include <vector>

// defines TournamentNode class
// class includes public constructor and destructor, other important variables and methods
// class includes private m_winner, m_hasData, is a friend class to TournamentTree
class TournamentNode
{
private:
    TournamentNode* m_winner;
    bool m_hasData;
    friend class TournamentTree; // friend class with TournamentTree
public:
    Monster m_data;
    TournamentNode* m_left;
    TournamentNode* m_right;
    TournamentNode();
    TournamentNode(Monster monster);
    virtual ~TournamentNode();
    Monster fight();
    void setData(Monster monster);
};

#endif