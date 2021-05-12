/*************************************************************
 *
 * Title: Game.cpp
 * Author: Changxuan Zhao
 * Date: 2019-03-05
 *
 *************************************************************/ 

#include "Game.h"
#include <cassert>

//This function is used to print the top line and bottom line represented as border.
void printBorder ();

bool Game :: invariant () const
{
    return (monsterPtr != nullptr);
}

void Game::deep_copy (const Game& game)
{
    level = game.level;
    player = game.player;
    monsterPtr = new Monster *[level.getMonsterCount()];
    for (int i = 0; i < level.getMonsterCount(); i++)
    {
        monsterPtr[i] = game.monsterPtr[i] -> getClone();
    }
    
    assert(invariant());
}

void Game::deallocate ()
{
    assert(invariant());
    
    for (int i = 0; i < level.getMonsterCount(); i++)
    {
        delete monsterPtr[i];
    }
    
    delete [] monsterPtr;
}

void Game::tryMove (const Position& p)
{
    assert(invariant());
    
    for (int m = 0; m < level.getMonsterCount(); m++)
    {
        if (areEqual(p, monsterPtr[m] -> getPosition()))
        {
            if (!monsterPtr[m] -> isDead())
            {
                monsterPtr[m] -> receiveDamage(player.getDamage());
                
                if (monsterPtr[m] -> isDead())
                {
                    player.increaseScore(monsterPtr[m] -> getPoints());
                }
                
                assert(invariant());
                return;
            }
            else
            {
                assert(isValid(p));
                
                player.increaseTotalMoveCost(level.getCost(monsterPtr[m] -> getPosition()));
                player.setPosition(p);
                
                assert(invariant());
                return;
            }
        }
    }
    
    if (isValid(p) && !level.isWall(p))
    {
        player.increaseTotalMoveCost(level.getCost(p));
        player.setPosition(p);
    }
    
    assert(invariant());
    return;
}

Game::Game ()
    :level(), player(toPosition(0, 0))
{
    monsterPtr = new Monster *[0];
    
    assert(invariant());
}

Game::Game (const string& file_name)
       :level(file_name), player(level.getPlayerStart())
{
    monsterPtr = new Monster *[level.getMonsterCount()];
    
    unsigned int next = 0;
    
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
        {
            if (level.getValue(toPosition(r, c)) == SENTRY_START)
            {
                monsterPtr[next] = new Sentry(toPosition(r, c));
                
                next++;
            }
            else if (level.getValue(toPosition(r, c)) == ATTACKER_START)
            {
                monsterPtr[next] = new Attacker(toPosition(r, c));
                
                next++;
            }
            else if (level.getValue(toPosition(r, c)) == DRONE_START)
            {
                monsterPtr[next] = new Drone(toPosition(r, c));
                
                next++;
            }
            else
            {
                //do nothing
            }
        }
    }
    
    assert(next == level.getMonsterCount());
    
    assert(invariant());
}

Game::Game (const Game& original)
{
    deep_copy(original);
    
    assert(invariant());
}

Game::~Game ()
{
    deallocate();
}

Game& Game::operator=(const Game& original)
{
    if (&original != this)
    {
        deallocate();
        deep_copy(original);
    }
    
    return *this;
}

bool Game::isOver () const
{
    assert(invariant());
    
    return (player.isDead() || level.isGoalPosition(player.getPosition()));
}

void Game::print () const
{
    assert(invariant());
    
    printBorder();
    
    for (int i = 0; i < ROWS; i++)
    {
        cout<<"|";
        
        for (int j = 0; j < COLUMNS; j++)
        {
            Position here;
            here.row = i;
            here.column = j;
            
            bool check = false;
            
            if (areEqual(here, player.getPosition()))
            {
                if (!player.isDead())
                {
                    cout<<'@';
                    check = true;
                }
            }
            else
            {
                for (int m = 0; m < level.getMonsterCount(); m++)
                {
                    if (areEqual(here, monsterPtr[m] -> getPosition()) && !monsterPtr[m] -> isDead())
                    {
                        cout<<monsterPtr[m] -> getDisplayChar ();
                        check = true;
                    }
                }
            }
            
            if (!check)
            {
                if (level.getValue(here) == PLAYER_START   ||
                    level.getValue(here) == SENTRY_START   ||
                    level.getValue(here) == ATTACKER_START ||
                    level.getValue(here) == DRONE_START)
                {
                    cout<<' ';
                }
                else
                {
                    level.printAtPosition(here);
                }
            }
        }
            
        cout<<"|"<<endl;
    }
    
    printBorder();
    
    cout<<"Health: "<<player.getHealth()<<setw(15)
        <<"Move cost: "<<player.getTotalMoveCost()<<setw(11)
        <<"score: "<<player.getScore()<<endl;
    
    if (Game::isOver())
    {
        cout<<endl;
        cout<<"Game over"<<endl
            <<"Total move cost: "<<player.getTotalMoveCost()<<endl
            <<"Final score: "<<player.getScore()<<endl<<endl
            <<"Hit ENTER key to terminate program";
    }
    
    return;
}

void Game::tryMoveNorth ()
{
    assert(invariant());
    
    Position p;
    p = player.getPosition();
    p = toPosition((p.row - 1), p.column);
    
    tryMove(p);
    
    assert(invariant());
    return;
}

void Game::tryMoveSouth ()
{
    assert(invariant());
    
    Position p;
    p = player.getPosition();
    p = toPosition((p.row + 1), p.column);
    
    tryMove(p);
    
    assert(invariant());
    return;
}

void Game::tryMoveEast ()
{
    assert(invariant());
    
    Position p;
    p = player.getPosition();
    p = toPosition(p.row, (p.column + 1));
    
    tryMove(p);
    
    assert(invariant());
    return;
}

void Game::tryMoveWest ()
{
    assert(invariant());
    
    Position p;
    p = player.getPosition();
    p = toPosition(p.row, (p.column-1));
    
    tryMove(p);
    
    assert(invariant());
    return;
}

void Game::updateMonsters ()
{
    assert(invariant());
    
    for (int m = 0; m < level.getMonsterCount(); m++)
    {
        if (!monsterPtr[m] -> isDead())
        {
            Position p;
            p = monsterPtr[m] -> calculateMove(*this, player.getPosition());
            
            if (areEqual(p, player.getPosition()))
            {
                player.receiveDamage(monsterPtr[m] -> getDamage());
            }
            else
            {
                assert(isValid(p));
                monsterPtr[m] -> setPosition(p);
            }
        }
    }
    
    assert(invariant());
    return;
}

bool Game::isBlockedForMonster (const Position& position) const
{
    assert(invariant());
    assert(isValid(position));
    
    if (level.isWall(position))
    {
        return true;
    }
    else
    {
        for (int m = 0; m < level.getMonsterCount(); m++)
        {
            if (areEqual(position, monsterPtr[m] -> getPosition()) && !monsterPtr[m] -> isDead())
            {
                return true;
            }
        }
    }
    
    return false;
}

void printBorder ()
{
    cout<<"+";
    for (int m = 0; m < 60; m++)
    {
        cout<<"-";
    }
    cout<<"+"<<endl;
    
    return;
}
