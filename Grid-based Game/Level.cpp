/****************************************************************************************
 *
 * Title: Level.cpp
 * Author: Changxuan Zhao
 * Date: Feb 11, 2019
 * Revision History: This module is modified to allow more monsters shown in the game
 *                   and the print function has been replaced by printAtPosition to print
 *                   a character corresponding to the position.
 *
 ****************************************************************************************/

#include "Level.h"
#include <cassert>

const unsigned int TERRAIN_COUNT = 9;
const char INPUT_TERRAIN_TYPE[TERRAIN_COUNT] = {'.', '^', ':', '#', 'P', '*', 'S', 'A', 'D',};
const char PRINTCHARACTER[] = {' ', '^', ':', '#', '@', '*', 'M', ' ', ' '};
const int TRAVERSALCOST[] = {1, 2, 4, 1000, 1, 1, 1, 1, 1};

//This function is used to check the input content is valid or not.
bool inputIsValid (char input);

//This function is used to convert input file contents into integers for the initializing constructor. 
int assignValue (char in);

void Level::copy (const Level& original)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            twoDimensionalArray[i][j] = original.twoDimensionalArray[i][j];
        }
    }
    
    numberOfMonster = original.numberOfMonster;
}

Level::Level ()
        : numberOfMonster(0)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == 0 && j == 0)
            {
                twoDimensionalArray[i][j] = PLAYER_START;
            }
            
            twoDimensionalArray[i][j] = EMPTY;
        }
    }
}

Level::Level (const string& filename)
        : numberOfMonster(0)
{
    extern const int MONSTER_COUNT_MAX;
    
    int counter = 0;
    
    ifstream infile(filename.c_str());
    if (!infile)
    {
        cout<<"Error! Cannot open the file"<<endl;
        exit (1);
    }
    
    char readFile[SIZE_OF_FILE];
    for (int s = 0; s < SIZE_OF_FILE; s++)
    {
        infile>>readFile[s];
        
        if (!inputIsValid(readFile[s]))
        {
            cout<< "Error: Invalid input, substituted empty terrain" << endl;
            readFile[s] = INPUT_TERRAIN_TYPE[0];
        }
    }
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            twoDimensionalArray[i][j] = assignValue(readFile[counter]);
            if (twoDimensionalArray[i][j] == -1)
            {
                cout<<"Error!"<<endl;
                infile.close();
                exit (1);
            }
            counter++;
            
            if ((twoDimensionalArray[i][j] == SENTRY_START) ||
                (twoDimensionalArray[i][j] == ATTACKER_START) ||
                (twoDimensionalArray[i][j] == DRONE_START))
            {
                numberOfMonster++;
            }
        }
    }
    
    infile.close();
    
    return;
}

Level::Level (const Level& original)
{
    copy(original);
}

Level::~Level ()
{
    
}

Level& Level::operator= (const Level& original)
{
    if (this != &original)
    {
        copy(original);
    }
    
    return *this;
}

Position Level::getPlayerStart () const
{
    Position P;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (twoDimensionalArray[i][j] == PLAYER_START)
            {
                P.row = i;
                P.column = j;
            }
        }
    }
    return P;
}

unsigned int Level::getMonsterCount () const
{
    return numberOfMonster;
}

unsigned int Level::getValue (const Position& p) const
{
    assert(isValid(p));
    
    assert(twoDimensionalArray[p.row][p.column] < TERRAIN_COUNT);
    
    return (twoDimensionalArray[p.row][p.column]);
}

void Level::printAtPosition (const Position& p) const
{
    assert(isValid(p));
    
    assert(twoDimensionalArray[p.row][p.column] < TERRAIN_COUNT);
    
    cout<<PRINTCHARACTER[twoDimensionalArray[p.row][p.column]];
}

unsigned int Level::getCost (const Position& p) const
{
    assert(isValid(p));
    
    assert(twoDimensionalArray[p.row][p.column] < TERRAIN_COUNT);
    
    return TRAVERSALCOST[twoDimensionalArray[p.row][p.column]];
}

bool Level::isWall (const Position& p) const
{
    assert(isValid(p));
    
    assert(twoDimensionalArray[p.row][p.column] < TERRAIN_COUNT);
    
    return (twoDimensionalArray[p.row][p.column] == WALL);
}

bool Level::isGoalPosition (const Position& p) const
{
    assert(isValid(p));
    
    return (twoDimensionalArray[p.row][p.column] == PLAYER_GOAL);
}

bool inputIsValid (char input)
{
    bool is_valid = false;
    for (int i = 0; i < TERRAIN_COUNT; i++)
    {
        if (input == INPUT_TERRAIN_TYPE[i])
        {
            is_valid = true;
        }
    }
    
    return is_valid;
}

int assignValue (char in)
{
    int value;
    switch(in)
    {
        case '.': value = EMPTY; break;
        case '^': value = ROCKY; break;
        case ':': value = ROUGH; break;
        case '#': value = WALL; break;
        case 'P': value = PLAYER_START; break;
        case '*': value = PLAYER_GOAL; break;
        case 'S': value = SENTRY_START; break;
        case 'A': value = ATTACKER_START; break;
        case 'D': value = DRONE_START; break;
        default:  value = -1; break;
    }
    
    return value;
}

