/*
AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games
*/

#include "TournamentTree.h"

// Finals tree generator
TournamentTree::TournamentTree(TournamentNode* root) {
    m_root = root;
}

// constructor that uses a vector bracket
// sets all variables to correct values and calls createTree
TournamentTree::TournamentTree(std::vector<Monster> bracket) {
    m_bracket = bracket;
    m_root = nullptr;
    createTree(m_bracket);
    // populateTree(m_bracket);
}

// constructor that takes in a file name
// sets all variables to correct values
// modifies the bracked and creates the tree for this object
TournamentTree::TournamentTree(std::string file) {
    m_file = file;
    m_root = nullptr;
    m_reader.open(m_file);
    std::string name;
    int screamPower;
    while (m_reader >> name >> screamPower) {
        m_bracket.push_back(Monster(name, screamPower));
        std::cout<< m_bracket.size()<< std::endl;
    } 
    createTree(m_bracket); // uses the member bracket
}

// destructor
TournamentTree::~TournamentTree () {
    m_reader.close();
}

// createTree method takes in a bracked and creates a Tree from it
// uses placceholders in the tree, and uses createTreeHelper method to complete tasks
void TournamentTree::createTree(std::vector<Monster> bracket) {
    while ((bracket.size() & (bracket.size() - 1)) != 0) {
        bracket.push_back(Monster("BYE", -1)); // Add a placeholder "BYE" monster
    }

    std::cout << bracket.size() << std::endl;

    m_bracketSize = (2 * bracket.size()) - 1; // Total nodes in a full binary tree
    int currSize = 0; // Track current size of the tree
    int index = 0;
    createTreeHelper(m_root, currSize, 0, bracket, index); // Build the tree
}

// createTreeHelper method completes tree creation
// populates each tree node with the correct values
void TournamentTree::createTreeHelper(TournamentNode*& root, int& currSize, int currentLvl, std::vector<Monster>& bracket,
int& index) {
    int height = calculateMinHeight(bracket.size()); // geeks for geeks
    std::cout << "Level: " << currentLvl << std::endl;
    // Stop recursion if we've created all required nodes
    if (currSize > m_bracketSize || currentLvl > height) {
        return;
    }

    if (root == nullptr) {
        root = new TournamentNode();
        root -> m_hasData = false;
        ++currSize;
    }


    if (currentLvl == height - 1) {
        if (index >= m_bracketSize - 2) {
            root->m_data = bracket[index];
            root->m_hasData = true;
            std::cout << "Populating node with: " << root->m_data.getName() << std::endl;
            ++index;
        }
    } else if (currentLvl == height) {
        root->m_data = bracket[index];
        root->m_hasData = true;
        std::cout << "Populating node with: " << root->m_data.getName() << std::endl;
        ++index;
    }

    // uses recursion to complete the tree
    createTreeHelper(root->m_left, currSize, currentLvl + 1, bracket, index);
    createTreeHelper(root->m_right, currSize, currentLvl + 1, bracket, index);
}

// calculateMinHeight method returns an int of the minimum height of the tree
int TournamentTree::calculateMinHeight (int numLeaves) {
    if (numLeaves <= 0) {
        return -1; 
    }
    
    // Calculate the height by taking the log base 2 of the number of leaves
    int height = std::ceil(std::log2(numLeaves));
    
    return height;
}

// singleElim method completes logic for single elimination games
// uses tournamentHelper method
Monster TournamentTree::singleElim() {
    tournamentHelper(m_root);
    return m_root -> m_data;
}

// doubleElim method completes logic for double elimination games
// uses tournamentHelper and other methods to complete tasks
Monster TournamentTree::doubleElim() {
    int i = 0;
    while (i < m_losersBracket.size()) {
        if (m_losersBracket[i].getName() == "BYE" || m_losersBracket[i].getName() == "") {
            m_losersBracket.erase(m_losersBracket.begin() + i);
        } else {
            ++i; 
        }
    }
    printLosers();
    tournamentHelper(m_root);
    return m_root -> m_data;
}

// finalWinner method is used in double elimination to complete the game
// returns the final winner of double elimination rounds
Monster TournamentTree::finalWinner() {
    m_finals.push_back(singleElim());
    // printLosers();
    m_finals.push_back(doubleElim());
    if (m_finals[0].screamFight(m_finals[1])) {
        return m_finals[0];
    } else {
        return m_finals[1];
    }
}

// tournamentHelper method completes fight logic to finish the game
// method takes all possible changes into consideration
void TournamentTree::tournamentHelper(TournamentNode* root) {
    std::cout << "CURRENT NODE: " << root -> m_data.getName() << std::endl;
    if (root -> m_left == nullptr && root -> m_right == nullptr) {
        return;
    }  

    if (root->m_left != nullptr) {
        std::cout << "Left Node: " << root->m_left->m_data.getName() << std::endl;
    } 

    if (root->m_right != nullptr) {
        std::cout << "Right Node: " << root->m_right->m_data.getName() << std::endl;
    } 

    std::cout << "Go Left" << std::endl;
    tournamentHelper(root->m_left);
    if (root -> m_right != nullptr) {
        std::cout << "Go Right" << std::endl;
        tournamentHelper(root->m_right);
    }

    if (root -> m_left && root -> m_right) {
        m_losersBracket.push_back(root -> fight());
    }
}

// printLosers method prints the loser of the game
void TournamentTree::printLosers() {
    std::cout << "\nLOSER Size: " << m_losersBracket.size() << std::endl;
    for (int i = 0; i < m_losersBracket.size(); ++i) {
        std::cout << m_losersBracket[i].getName() << std::endl;
    }
}

void TournamentTree::saveTreeAsDotHelper(TournamentNode* node, std::ofstream& file, int& nodeID) {
    if (node == NULL) return;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node-> m_data.getName()
         << " (Power: " << node->m_data.getScream() << ")\"];\n";

    if (node->m_left) {
        int leftID = nodeID;
        saveTreeAsDotHelper(node->m_left, file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->m_right) {
        int rightID = nodeID;
        saveTreeAsDotHelper(node->m_right, file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }
}

// Function to save the tree as a DOT file
void TournamentTree::saveTreeAsDot(const std::string& filename, TournamentNode* rootNode) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for DOT output: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n";
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID);
    file << "}\n";
    file.close();
}
