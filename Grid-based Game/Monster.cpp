/******************************************************************************
 *
 * Title: Monster.cpp
 * Author: Changxuan Zhao 
 * Date: Feb 10, 2019
 *
 ******************************************************************************/

#include "Monster.h"
#include <cassert>
#include "Game.h"

int test = 0;

const int STARTING_HEALTH = 20;
const int DAMAGE = 3;
const int POINTS = 50;

void Monster::copy (const Monster& original)
{
    health = original.health;
    damage = original.damage;
    position = original.position;
    points = original.points;
}

Monster::Monster ()
{
    health = 0;
    damage = DAMAGE;
    position.row = 0;
    position.column = 0;
    points = POINTS;
    
    test++;
}

Monster::Monster (const Position& start)
{
    assert(isValid(start));
    
    health = STARTING_HEALTH;
    damage = DAMAGE;
    position = start;
    points = POINTS;
    
    test++;
}

Monster::Monster (const Monster& original)
{
    assert(isValid(original.position));
    
    copy(original);
    
    test++;
}

Monster::~Monster ()
{
    test--;
}

Monster& Monster::operator= (const Monster& original)
{
    if (this != &original)
    {
        copy(original);
    }
    
    return *this;
}

bool Monster::isDead () const
{
    return (health <= 0);
}

int Monster::getDamage () const
{
    return damage;
}

unsigned int Monster::getPoints () const
{
    return points;
}

const Position& Monster::getPosition () const
{
    return position;
}

void Monster::setPosition (const Position& p)
{
    assert(isValid(p));
    
    position = p;
}

void Monster::receiveDamage (int amount)
{
    health -= amount;
}

Position Monster::calculateToPosition (const Game& game, const Position& target_position) const
{
    assert(isValid(target_position));

    const double FAR_DISTANCE = 1.0e40;
    
    Position monsterOldPosition, monsterPosition, positionNorth, positionSouth, positionEast, positionWest;

    monsterOldPosition = position;
    
    double north, south, east, west, current;
        
    monsterOldPosition.row--;
    north = calculateDistance(monsterOldPosition, target_position);
    positionNorth = monsterOldPosition;
    monsterOldPosition = position;
        
    monsterOldPosition.row++;
    south = calculateDistance(monsterOldPosition, target_position);
    positionSouth = monsterOldPosition;
    monsterOldPosition = position;
        
    monsterOldPosition.column++;
    east = calculateDistance(monsterOldPosition, target_position);
    positionEast = monsterOldPosition;
    monsterOldPosition = position;
    
    monsterOldPosition.column--;
    west = calculateDistance(monsterOldPosition, target_position);
    positionWest = monsterOldPosition;
    monsterOldPosition = position;
        
    current = calculateDistance(monsterOldPosition, target_position);
    
    if (!isValid(positionNorth) || game.isBlockedForMonster(positionNorth))
    {
        north = FAR_DISTANCE;
    }
    
    if (!isValid(positionSouth) || game.isBlockedForMonster(positionSouth))
    {
        south = FAR_DISTANCE;
    }
    
    if (!isValid(positionWest) || game.isBlockedForMonster(positionWest))
    {
        west = FAR_DISTANCE;
    }
    
    if (!isValid(positionEast) || game.isBlockedForMonster(positionEast))
    {
        east = FAR_DISTANCE;
    }
    
    if((north < south) && (north <= east) && (north <= west) && (north < current))
    {
        monsterPosition = positionNorth;
    }
    else if ((south <= east) && (south <= west) && (south <current))
    {
        monsterPosition = positionSouth;
    }
    else if ((east < west) && (east < current))
    {
        monsterPosition = positionEast;
    }
    else if (west < current)
    {
        monsterPosition = positionWest;
    }
    else
    {
        monsterPosition = monsterOldPosition;
    }
    
    return monsterPosition;
}

