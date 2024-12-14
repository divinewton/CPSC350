/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#include "TournamentNode.h"

// default constructor
// sets all variables to NULL
TournamentNode::TournamentNode() {
    m_data = Monster();
    m_winner = NULL;
    m_left = NULL;
    m_right = NULL;
}

// overloaded constructor
// sets variables to NULL and sets data to a specified Monster
TournamentNode::TournamentNode(Monster monster) {
    m_data = monster;
    m_winner = NULL;
    m_left = NULL;
    m_right = NULL;
}

// destructor
TournamentNode::~TournamentNode() {
    
}

// fight method returns the loser based on two monsters fighting each other
// contains all nessesary logic for fighting monsters in a node
Monster TournamentNode::fight() {
    Monster loser;
    std::cout << "Fighting: " << m_left->m_data.getName() << " vs " << m_right->m_data.getName() << std::endl;
    if (m_left -> m_data.getScream() == m_right -> m_data.getScream()) { // if the screams are equal
        m_winner = m_left;
        setData(m_winner->m_data);
        loser = m_right->m_data;
        return loser;
    }
    if (m_right -> m_hasData) { // if the right side has data
        if (m_left->m_data.screamFight(m_right->m_data)) {
            m_winner = m_left;
            setData(m_winner->m_data);
            loser = m_right->m_data;
        } else {
            m_winner = m_right;
            loser = m_left->m_data;
        }   
    } else { // if right side has no data
        if (m_right == nullptr) {
            m_winner = m_left;
            setData(m_winner -> m_data);
            loser = Monster();
        }
        m_winner = m_left;
        setData(m_winner -> m_data);
        loser = m_right -> m_data;
    }
    std::cout << "Loser: " << loser.getName() << std::endl;
    return loser; // returns the looser
}


// setData method sets the data of a node (the winner) to a specific monster
// used from fight method to define the winner in a TournamentNode object
void TournamentNode::setData(Monster monster) {
    m_data = monster;
}