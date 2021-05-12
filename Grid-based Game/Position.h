//
//  Position.h
//
//  This module defines an abstract data type named Position. Encapsulates
//    the module to set a new position, check positions, and determine the
//    distance between two positions in a grid-based game.
//

#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int row;
    int column;
};


//
//  toPosition
//
//  Purpose: To set Position of the player or monster.
//  Parameter(s):
//    <1> row: An integer represents the numbers of the row.
//    <2> column: An integer represents the numbers of the column.
//  Precondition(s): N/A
//  Returns: The Position is assigned value with int row as the numbers of row and int column as the numbers of column.
//  Side Effect: N/A
//
Position toPosition (int row, int column);

//
//  areEqual
//
//  Purpose: To determine if the Positions are the same.
//  Parameter(s):
//    <1> p1: The Position to check.
//    <2> P2: The Position to check.
//  Precondition(s): N/A
//  Returns: Whether Position p1 and Position p2 are the same.
//  Side Effect: N/A
//
bool areEqual (const Position& p1, const Position& p2);

//
//  isValid
//
//  Purpose: To determine if the Position is inside the border.
//  Parameter(s):
//    <1> p1: Position to check.
//  Precondition: N/A
//  Returns: Whether Position p1 is inside the border.
//  Side Effect: N/A
//
bool isValid (const Position& p1);

//
//  calculateDistance
//
//  Purpose: To calculate the distance between two Positions.
//  Parameter(s):
//    <1> p1: The first Position.
//    <2> P2: The second Position.
//  Precondition: N/A
//  Returns: The distance between Position p1 and Position p2.
//  Side Effect: N/A
//
double calculateDistance (const Position& p1, const Position& p2);

#endif
