#include "Game.h"
#include "Sentry.h"
#include <cmath>

void Sentry::copy (const Sentry& original)
{
    health = original.health;
    damage = original.damage;
    points = original.points;
    setPosition(original.getPosition());
    start_position = original.start_position;
}

void Sentry::assignValue (const Position& position)
{
    health = 20;
    damage = 3;
    points = 50;
    setPosition(position);
    start_position = position;
}

Sentry::Sentry ()
{
    assignValue(toPosition(0, 0));
}

Sentry::Sentry (const Position& start)
{
    assignValue(start);
}

Sentry::Sentry (const Sentry& original)
{
    copy(original);
}

Sentry::~Sentry ()
{
    //empty body
}

Sentry& Sentry::operator= (const Sentry& original)
{
    if (this != &original)
    {
        copy(original);
    }
    
    return *this;
}

char Sentry::getDisplayChar () const
{
    return 'S';
}

Monster* Sentry::getClone () const
{
    return new Sentry(*this);
}

Position Sentry::calculateMove (const Game& game,
                                const Position& player_Posiiton)
{
    double distance = sqrt(pow((player_Posiiton.row - getPosition().row), 2) +
                           pow((player_Posiiton.column - getPosition().column), 2)) +
                      sqrt(pow((start_position.row - getPosition().row), 2) +
                           pow((start_position.column - getPosition().column), 2));
                      
    if (distance <= 6)
    {
        return calculateToPosition(game, player_Posiiton);
    }
    else
    {
        return calculateToPosition(game, start_position);
    }
}
