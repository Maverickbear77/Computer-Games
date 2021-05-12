//
//  Level.h
//
//  This module defines a Level class. Encapsulates the module
//    to initialize the Level by reading contents from an input
//    file, find the starting positions of a player and monster,
//    calculate the cost for movement, check if a position is a 
//    wall, and print out the character on a specified position.
//  

#ifndef Level_h
#define Level_h
#include "Position.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

const int ROWS = 20;
const int COLUMNS = 60;
const int SIZE_OF_FILE = 1200;
const unsigned int EMPTY = 0, ROCKY =1 , ROUGH = 2, WALL = 3, PLAYER_START = 4,
                   PLAYER_GOAL = 5, SENTRY_START = 6, ATTACKER_START = 7, DRONE_START = 8;

class Level
{
    private:
        unsigned int twoDimensionalArray[ROWS][COLUMNS];
        unsigned int numberOfMonster;
    
        void copy (const Level& original);
    
    public:
    
        Level (const Level& original);
    
        ~Level ();
    
        Level& operator= (const Level& original);
    
//
//  default constructor
//
//  Purpose: To initialize a Level with default values.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The Level is initialized with value EMPTY for each element in the 2D array
//               except the top left corner, which is set to PLAYER_START.
//
        Level ();
    
//
//  initializing constructor
//
//  Purpose: To initialize a Level by reading contents from an input file.
//  Parameter(s): 
//    <1> filename: The name of the input file.
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: Checking if the file can be opened. If not, terminate the program and output 
//		 an error message. Then checking if the contents of the input file is valid 
//		 or not. If it is invalid, output a error message and convert the invalid 
//		 content into a valid one. Finally, the Level is initialized with the valid
//		 contents.
//  
        Level (const string& filename);
    
//
//  getPlayerStart
//
//  Purpose: To find the starting position of a player.
//  Parameter(s): N/A
//  Precodition: N/A
//  Returns: The starting position of a player.
//  Side Effect: N/A
//
        Position getPlayerStart () const;
    
//
// getMonsterCount
//
// Purpose: To count how mnay monsters in the game.
// Parameter(s): N/A
// Precondition: N/A
// Returns: The number of monsters in the game.
// Side Effect: N/A
//
       unsigned int getMonsterCount () const;
    
//
// getValue
//
// Purpose: To get the value represented the character of the Position.
// Parameter(s):
//   <1> p: The Position to check.
// Precondition:
//   <1> isValid(p)
// Returns: The value of the Position.
// Side Effect: N/A
//
       unsigned int getValue (const Position& p) const;
    
//
// printAtPosition
//
// Purpose: Print the corresponding character to the Position.
// Parameter(s):
//   <1> p: The Position to print.
// Precondiition:
//   <1> isValid(p)
// Returns: N/A
// Side Effect: Print the character of the Position p.
//
       void printAtPosition (const Position& p) const;

//
//  getCost
//
//  Purpose: To calculate the cost of a movement.
//  Parameter(s):
//    <1> p: The Position to calculate the cost.
//  Precondition:
//    <1> isValid(p)
//  Returns: How much traversal cost for the movement.
//  Side Effect: N/A
//
        unsigned int getCost (const Position& p) const;

//
//  isWall
//
//  Purpose: To check if the Position is a wall.
//  Parameter(s): 
//    <1> p: The Position to check.
//  Precondition:
//    <1> isValid(p)
//  Returns: Whether Position p is a wall.
//  Side Effect: N/A
//    
        bool isWall (const Position& p) const;
    
//
// isGoalPosition
//
// Purpose: To check if the Position is the playr goal.
// Parameter(s):
//   <1> p: The Position to check.
// Precondition:
//   <1> isValid(p)
// Returns: Whether Posiiton p is the player goal.
// Side Effect: N/A
//
       bool isGoalPosition (const Position& p) const;

};

#endif
