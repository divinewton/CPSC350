/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#ifndef TOURNAMENTTREE_H
#define TOURNAMENTTREE_H

#include "TournamentNode.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

// defines TournamentTree class
// class includes public constructor and destructor, and other methods
// class includes private m_bracket, m_reader, m_file, m_bracketSize, and nessesary helper methods
class TournamentTree
{
private:
    std::vector<Monster> m_bracket;
    std::ifstream m_reader;
    std::string m_file;
    int m_bracketSize;
    void createTreeHelper(TournamentNode*& root, int& currSize, int currentLvl, std::vector<Monster>& bracket, int& index);
    void tournamentHelper(TournamentNode* root);

public:
    std::vector<Monster> m_finals;
    std::vector<Monster> m_losersBracket;
    TournamentNode* m_root;
    TournamentTree(TournamentNode* root);
    TournamentTree(std::vector<Monster> bracket);
    TournamentTree(std::string file);
    virtual ~TournamentTree();
    void createTree(std::vector<Monster> bracket);
    Monster singleElim();
    Monster doubleElim();
    Monster finalWinner();
    void printLosers();
    int calculateMinHeight(int numLeaves);
    void saveTreeAsDotHelper(TournamentNode* node, std::ofstream& file, int& nodeID);
    void saveTreeAsDot(const std::string& filename, TournamentNode* rootNode);
};

#endif