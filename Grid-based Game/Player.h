//
//  Player.h
//
//  Encapsulates a module to represent the player in a
//    grid-based game.
//

#pragma once

#include "Position.h"

class Player
{
    private:
        int health;
        int damage;
        Position position;
        unsigned int score;
        unsigned int total_move_cost;
    
        void copy (const Player& original);
    
    public:
    
        Player (const Player& original);
    
        ~Player ();
    
        Player& operator= (const Player& original);
    
        Player ();
    
    
//
//  initializing constructor
//
//  Purpose: To initialize a Player at a specific position.
//  Parameter(s):
//    <1>> start: The starting position for Player
//  Precondition(s):
//    <1> isValid(start)
//  Returns: N/A
//  Side Effect: The Player is initialized to have default
//               values and to be at the position start.
//
        Player (const Position& start);

//
//  isDead
//
//  Purpose: To determine if a Player is dead.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: Whether the Player is dead
//  Side Effect: N/A
//
        bool isDead () const;

//
//  getHealth
//
//  Purpose: To determine a Player's current health.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: The Player's current health.
//  Side Effect: N/A
//
        int getHealth () const;

//
//  getDamage
//
//  Purpose: To determine how much damage a Player deals when
//           attacking.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: How much damage the Player deals when attacking.
//  Side Effect: N/A
//
        int getDamage () const;

//
//  getScore
//
//  Purpose: To determine a Player's current score.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: The Player's current score.
//  Side Effect: N/A
//
        unsigned int getScore () const;

//
//  getTotalMoveCost
//
//  Purpose: To determine a Player's total movement cost.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: The Player's total movement cost.
//  Side Effect: N/A
//
        unsigned int getTotalMoveCost () const;

//
//  getPosition
//
//  Purpose: To determine a Player's current position.
//  Parameter(s): N/A
//  Precondition(s): N/A
//  Returns: The Player's current position.
//  Side Effect: N/A
//
        const Position& getPosition () const;

//
//  setPosition
//
//  Purpose: To change a Player's current position.
//  Parameter(s):
//    <1> p: The new position
//  Precondition(s):
//    <1> isValid(p)
//  Returns: N/A
//  Side Effect: The current Position of the Player is set to
//               p if it is a valid Position.
//
        void setPosition (const Position& p);

//
//  receiveDamage
//
//  Purpose: To reduce a Player's health.
//  Parameter(s):
//    <1> amount: The amount to reduce Player's health by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The health of the Player is reduced by
//               amount.
//
        void receiveDamage (int amount);

//
//  increaseScore
//
//  Purpose: To increase a Player's current score.
//  Parameter(s):
//    <1> amount: The amount to increase Player's current score
//                by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The current score of the Player is increased
//               by amount.
//
        void increaseScore (unsigned int amount);

//
//  increaseTotalMoveCost
//
//  Purpose: To increase a Player's total move cost.
//  Parameter(s):
//    <1> amount: The amount to increase Player's total move
//                cost by
//  Precondition(s): N/A
//  Returns: N/A
//  Side Effect: The total move cost of the Player is
//               increased by amount.
//
        void increaseTotalMoveCost (unsigned int amount);
};
