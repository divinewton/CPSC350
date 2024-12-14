AUTHOR INFO
Names: Joshua Vaysman, Divi Newton
Student IDs: 2449656, 2440117
Emails: vaysman@chapman.edu, dnewton@chapman.edu
Class Section: CPSC-350-02
Assignment: PA5 - Scare Games

SUBMISSION CONTENTS
- main.cpp
- Monster.cpp
- Monster.h
- RunScareGame.cpp
- RunScareGame.h
- TournamentNode.cpp
- TournamentNode.h
- TournamentTree.cpp
- TournamentTree.h
- README.txt

KNOWN ERRORS 
- None

REFERENCES
We used the following articles for help with specific programming syntax:
- Geeks for Geeks
- We also used the DOT file code provided in the project spec

RUNNING INSTRUCTIONS
input note: all screamPower should be positive, our BYE placeholders are set to -1, 
    and anything lower will stop them from working
    
note: ensure to replace "input.txt" and "output.js" with the correct input and output file names, 
    and replace "double" with either "single" or "double" to indicate game elimination type

    g++ -o tournament *.cpp
    ./tournament input.txt output.js double