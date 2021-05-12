//
//  Monster.h
//
//  Encapsulates a module to represent an (enemy) monster in a
//    grid-based game.
//

#ifndef MONSTER_H
#define MONSTER_H
#include "Position.h"

class Game;

class Monster
{
    public:
    
        Monster& operator= (const Monster& original);
    
        virtual char getDisplayChar () const = 0;
    
        virtual Monster* getClone () const = 0;
    
        virtual Position calculateMove (const Game& game,
                                        const Position& player_position) = 0;

//
//  default constructor
//
//  Purpose: To initialize a Monster with default values.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The Monster is initialized to have default values.
//   
        Monster ();

//
//  initializing constructor
//
//  Purpose: To initialize a Monster at a specific position.
//  Parameter(s):
//    <1> start: The starting position for the monster
//  Precondition:
//    <1> isValid(start)
//  Returns: N/A
//  Side Effect: The Monster is initialized to have values and 
//               to be at position start.
//
        Monster (const Position& start);
    
//
//  copy constructor
//
//  Purpose: Initialize a new Monster instance to contain copies of
//           the members of another Monster.
//  Parameter(s):
//    <1> monsterPtr: A pointer of the Monster to copy.
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The Monster instance is initialized to contain a copy
//               of each member of monsterPtr.
//
        Monster (const Monster& original);
    
//
//  destructor
//
//  Purpose: Safely destroy a Monster instance without memory leaks.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: N/A
//  Side Effect: The Monster is destroied.
//
        virtual ~Monster ();

//
//  isDead
//
//  Purpose: To determine if a Monster is dead.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: Whether the Monster is dead.
//  Side Effect: N/A
//
        bool isDead () const;

//
//  getDamage
//
//  Purpose: To determine how much damage a Monster deals when
//           attacking.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: How much damage a Monster deals when attacking.
//  Side Effect: N/A
//
        int getDamage () const;

//
//  getPoints
//
//  Purpose: To determine how many points are awarded for
//           killing a Monster.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: How many points are awarded for killing the Monster.
//  Side Effect: N/A
//
        unsigned int getPoints () const;

//
//  getPosition
//
//  Purpose: To determine a Monster's current position.
//  Parameter(s): N/A
//  Precondition: N/A
//  Returns: The Monster's current position.
//  Side Effect: N/A
//
        const Position& getPosition () const;

//
//  setPosition
//
//  Purpose: To change a Monster's current position.
//  Parameter(s):
//    <1> p: The new position
//  Precondition: 
//    <1> isValid(p)
//  Returns: N/A
//  Side Effect: The current Position of the Monster is set
//               to p if it is a valid Position.
//
        void setPosition (const Position& p);

//
//  receiveDamage
//
//  Purpose: To reduce a Monster's health.
//  Parameter(s):
//    <1> amount: The amount to reduce the Monster's health by
//  Precondition:
//    <1> isValid(p)
//  Returns: N/A
//  Side Effect: The Monster's health is reduced by amount.
//
        void receiveDamage (int amount);
    

    protected:
        int health;
        int damage;
        unsigned int points;
    
//
//  calculateToPosition
//
//  Purpose: To calculate a Monster's next move in the game.
//  Parameter(s):
//    <1> game: The entire Game to check if the new position is
//              blocked by other monsters or a wall.
//    <2> target_position: The target's current position
//  Precondition:
//    <1> isValid(target_position)
//  Returns: The new position for the Monster.  If this is
//           the same as the target's position, the Monster
//           can not make a move to that position.
//  Side Effect: N/A
//
       Position calculateToPosition (const Game& game,
                                     const Position& target_position) const;
    
    private:
        Position position;
    
        void copy (const Monster& original);
};

#endif
