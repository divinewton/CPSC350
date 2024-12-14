/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#include "RunScareGame.h"

// overloaded constructor with file names and game type included
// sets all of the variables to the correct local names
RunScareGame::RunScareGame(std::string inputFile, std::string outputFile, std::string gameType) {
    m_input = inputFile;
    m_output = outputFile;
    m_type = gameType; // can be single or double
}

// default constructor sets default values to local variables
RunScareGame::RunScareGame() {
    m_input = "input.txt";
    m_output = "output.dot";
    m_type = "single";
}

// destructor
RunScareGame::~RunScareGame() {

}

// runTournament method completes logic based on the specified game type
// method called TournamentTree methods to complete logic
void RunScareGame::runTournament() {
    if (m_type == "double") {

        TournamentTree tree(m_input);
        tree.singleElim();
        TournamentTree doubleTree(tree.m_losersBracket);
        doubleTree.doubleElim();

        TournamentNode* root = new TournamentNode();
        root -> m_left = tree.m_root;
        root -> m_right = doubleTree.m_root;
        root->fight();
        TournamentTree finals(root);
        finals.saveTreeAsDot(m_output, root); // outputs to dot file
    } else {
        
        TournamentTree tree(m_input);
        tree.singleElim();
        tree.saveTreeAsDot(m_output, tree.m_root); // outputs to dot file
    }
}
