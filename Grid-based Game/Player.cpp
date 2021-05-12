/******************************************************************************
 *
 * Title: Player.cpp
 * Author: Changxuan Zhao 
 * Date: Feb 10, 2019
 *
 ******************************************************************************/

#include "Player.h"
#include <cassert>

const int STARTING_HEALTH = 40;
const int DAMAGE = 2;

void Player::copy (const Player& original)
{
    health = original.health;
    damage = original.damage;
    position = original.position;
    score = original.score;
    total_move_cost = original.total_move_cost;
}

Player::Player ()
{
    health = STARTING_HEALTH;
    damage = DAMAGE;
    position = toPosition(0, 0);
    score = 0;
    total_move_cost = 0;
}

Player::Player (const Position& start)
{
    assert(isValid(start));
    
    health = STARTING_HEALTH;
    damage = DAMAGE;
    position = start;
    score = 0;
    total_move_cost = 0;
}

Player::Player (const Player& original)
{
    assert(isValid(original.position));
    
    copy(original);
}

Player::~Player()
{
    
}

Player& Player::operator= (const Player& original)
{
    if (this != &original)
    {
        copy(original);
    }
    
    return *this;
}

bool Player::isDead () const
{
    return (health <= 0);
}

int Player::getHealth () const
{
    return health;
}

int Player::getDamage () const
{
    return damage;
}

unsigned int Player::getScore () const
{
    return score;
}

unsigned int Player::getTotalMoveCost () const
{
    return total_move_cost;
}

const Position& Player::getPosition () const
{
    return position;
}

void Player::setPosition (const Position& p)
{
    assert(isValid(p));
    
    position = p;
}

void Player::receiveDamage (int amount)
{
   health -= amount;
}

void Player::increaseScore (unsigned int amount)
{
    score += amount;
}

void Player::increaseTotalMoveCost (unsigned int amount)
{
    total_move_cost += amount;
}
