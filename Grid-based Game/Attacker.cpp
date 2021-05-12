#include "Game.h"
#include "Attacker.h"

void Attacker::copy (const Attacker& original)
{
    health = original.health;
    damage = original.damage;
    points = original.points;
    setPosition(original.getPosition());
}

void Attacker::assignValue (const Position& position)
{
    health = 10;
    damage = 2;
    points = 20;
    setPosition(position);
}

Attacker::Attacker ()
{
    assignValue(toPosition(0, 0));
}

Attacker::Attacker (const Position& start)
{
    assignValue(start);
}

Attacker::Attacker (const Attacker& original)
{
    copy(original);
}

Attacker::~Attacker ()
{
    //empty body
}

Attacker& Attacker::operator= (const Attacker& original)
{
    if (this != &original)
    {
        copy(original);
    }
    
    return *this;
}

char Attacker::getDisplayChar () const
{
    return 'A';
}

Monster* Attacker::getClone () const
{
    return new Attacker(*this);
}

Position Attacker::calculateMove (const Game& game,
                                  const Position& player_Posiiton)
{
    return calculateToPosition(game, player_Posiiton);
}
