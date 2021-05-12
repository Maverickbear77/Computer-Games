//
//  Game.h
//
//  This module defines a Game class to composite the Level, Player, and Monster classes.
//    Encapsulates the module to allow more than one Monster to be in the game.
//

#ifndef GAME_H
#define GAME_H
#include "Level.h"
#include "Player.h"
#include "Monster.h"
#include "Sentry.h"
#include "Attacker.h"
#include "Drone.h"

//
//  Game
//
//  A class to represent the current state of the game.
//
//  Class Invariant:
//    <1> monsterPtr != nullptr
//

class Game
{
    private:
        Level level;
        Player player;
        Monster** monsterPtr;
    
//
//  tryMove
//
//  Purpose: To move the player.
//  Parameter(s):
//    <1> p: The Position to check.
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: To move the player if the Position is valid and not a wall.
//               If a monster is on the Position, the player will attack it
//               instead of moveing.
//
        void tryMove (const Position& p);
    
//
//  invariant
//
//  Purpose: To determine if the class invariant is true.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether the class invariant is true.
//  Side Effect: N/A
//
        bool invariant () const;
    
//
//  deep_copy
//
//  Purpose: To creat a deep copy of the existing Game.
//  Parameter(s):
//    <1> game: The Game to copy.
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: A Game is copied to the existing Game.
//
        void deep_copy (const Game& game);
    
//
//  deallocate
//
//  Purpose: To safely deallocate all dynamically allocated
//           memory associated with the monster.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: All dynamically allocated memory associated
//               with the monster is freed.
//
        void deallocate ();
    
    public:
    
//
//  default constructor
//
//  Purpose: Initialize an empty Game instance.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The Game is initialized with default values.
//
        Game ();
    
//
//  initializing constructor
//
//  Purpose: To initialize the level, player, and monster.
//  Parameter(s):
//    <1> file_name: The file to initialize the level.
//  Precondition(s):
//    <1> next == numberOfMonster
//  Returns: N/A
//  Side Effect: The level is initialized by loading file content.
//               Then the player and monster are initialized to
//               their starting positions.
//
        Game (const string& file_name);
    
//
//  copy constructor
//
//  Purpose: Initialize a new Game instance to contain copies of
//           the members of another Game.
//  Parameter(s):
//    <1> original: The Game to copy.
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The Game instance is initialized to contain a
//               copy of each member of original.
//
        Game (const Game& original);
 
//
//  destructor
//
//  Purpose: Safely destroy a Game instance without memory leak.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: All dynamically allocated memory associated
//               with this Game is freed.
//
        ~Game ();
    
//
//  assignment operator
//
//  Purpose: Modify this Game instance to contain copies of the
//           members of another Game.
//  Parameter(s):
//    <1> original: The Game to copy.
//  Precondition(s): N/A
//  Returns: A reference to this Game.
//  Side Effect: The contents of this Game instance are set to be a copy
//               of the contents of original. The existing members, if
//               any, are lost.
//
        Game& operator = (const Game& original);
//
//  isOver
//
//  Purpose: To check if the game is over.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: Whether the game is over.
//  Side Effect: N/A
//
        bool isOver () const;
    
//
//  print
//
//  Purpose: To display the level including the player and monster.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: This level is displayed. If the position of the monster
//              is valid, an 'M' is displayed. If the player position
//              is valid, an '@' is displayed. Also, the information in
//              terms of player health, score, and move cost will be
//              displayed.
//
        void print () const;
    
//
//  tryMoveNorth
//
//  Purpose: Move the player position to north.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: To move the position of player to north.
//
        void tryMoveNorth ();

//
//  tryMoveSouth
//
//  Purpose: Move the player position to south.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: To move the position of player to south.
//
        void tryMoveSouth ();
    
//
//  tryMoveEast
//
//  Purpose: Move the player position to east.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: To move the position of player to east.
//
        void tryMoveEast ();
 
//
//  tryMoveWest
//
//  Purpose: Move the player position to west.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: To move the position of player to west.
//
        void tryMoveWest ();
    
//
//  updateMonsters
//
//  Purpose: To update the monsters next move.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: To move monsters if the position is valid and not occupied
//              by other monsters or a wall.
//
        void updateMonsters ();
    
//
//  isBlockedForMonster
//
//  Purpose: To check if the Position is blocked.
//  Parameter(s):
//    <1> position: The Position to check.
//  Precondition:
//    <1> isValid(position)
//  Returns: Whether the Position is blocked by other monsters or a wall.
//  Side Effect: N/A 
//
        bool isBlockedForMonster (const Position& position) const;
};


#endif 
