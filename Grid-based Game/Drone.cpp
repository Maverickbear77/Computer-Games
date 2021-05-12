
#include "Game.h"
#include "Drone.h"

void Drone::copy (const Drone& original)
{
    health = original.health;
    damage = original.damage;
    points = original.points;
    setPosition(original.getPosition());
    direction = original.direction;
}

void Drone::assignValue (const Position& position)
{
    health = 50;
    damage = 5;
    points = 10;
    setPosition(position);
    direction = 1;
}

Drone::Drone ()
{
    assignValue(toPosition(0, 0));
}

Drone::Drone (const Position& start)
{
    assignValue(start);
}

Drone::Drone (const Drone& original)
{
    copy(original);
}

Drone::~Drone ()
{
    //empty body
}

Drone& Drone::operator= (const Drone& original)
{
    if (this != &original)
    {
        copy(original);
    }
    
    return *this;
}

char Drone::getDisplayChar () const
{
    return 'D';
}

Monster* Drone::getClone () const
{
    return new Drone(*this);
}

Position Drone::calculateMove (const Game& game,
                               const Position& player_Posiiton)
{
    Position current = getPosition();
    
    if (direction == 1)
    {
        Position next = toPosition((current.row - 1), current.column);
        
        if (isValid(next) && !game.isBlockedForMonster(next))
        {
            return next;
        }
        else
        {
            direction = 2;
        }
    }
    else if (direction == 2)
    {
        Position next = toPosition(current.row, (current.column + 1));
        
        if (isValid(next) && !game.isBlockedForMonster(next))
        {
            return next;
        }
        else
        {
            direction = 3;
        }
    }
    else if (direction == 3)
    {
        Position next = toPosition((current.row + 1), current.column);
        
        if (isValid(next) && !game.isBlockedForMonster(next))
        {
            return next;
        }
        else
        {
            direction = 4;
        }
    }
    else
    {
        Position next = toPosition(current.row, (current.column - 1));
        
        if (isValid(next) && !game.isBlockedForMonster(next))
        {
            return next;
        }
        else
        {
            direction = 1;
        }
    }
    
    return current;
}
