/******************************************************************************
 *
 * Title: Position.cpp
 * Author: Changxuan Zhao 
 * Date: Jan 28, 2019
 *
 ******************************************************************************/

#include "Position.h"
#include "Level.h"

Position toPosition(int row, int column)
{
    Position P;
    P.row = row;
    P.column = column;
    return P;
}

bool areEqual (const Position& p1, const Position& p2)
{
    bool status = 0;
    
    if ((p1.row == p2.row) && (p1.column == p2.column))
    {
        status = 1;
    }

    return status;
}

bool isValid (const Position& p)
{
    bool status = 0;
     
    if ((p.row < ROWS) && (p.row >= 0) && (p.column >= 0) && (p.column < COLUMNS))
    {
        status = 1;
    }
 
    return status;
}

double calculateDistance(const Position& p1, const Position& p2)
{
    double distance;
          
    distance = sqrt(double((p1.row - p2.row) * (p1.row - p2.row) + (p1.column - p2.column) * (p1.column - p2.column)));
              
    return distance;
}
