/******************************************************************************
 *
 * Title: main.cpp
 * Author: Changxuan Zhao 
 * Date: Feb 14, 2019
 * Purpose: This program is to implement a simple grid-based combat game. In 
 *          this game, the player and the monster will take turns on moving
 * 	    or attacking until the player is killed. Please press "q" to
 * 	    terminate the program.
 * Revision History: Simplify this file by adding the Game class to update
 *                   the movement of Monster and print the entire Level.
 *
 ******************************************************************************/

#include "Game.h"
#include <cassert>

//This function is used to check if the user's input is valid.
char getValidInput ();

int main()
{
    string filename, termination;
    char continueCondition;

    cout<<"Please enter the name of the file to load, including the file extersion. "<<endl;
    getline(cin,filename);
    
    Game game(filename);
    
    if (true)
    {
        Game game2;
        Game game3(game);
        game = game3;
    }
    
    do
    {
        game.print();
        
        continueCondition = getValidInput();

        if (continueCondition != 'q')
        {
            switch(continueCondition)
            {
                case 'n': game.tryMoveNorth(); break;
                case 's': game.tryMoveSouth(); break;
                case 'e': game.tryMoveEast();  break;
                case 'w': game.tryMoveWest();  break;
                case '.':                      break;
            }
            
            game.updateMonsters();
            
            if (game.isOver())
            {
                cout<<endl<<"Game Over"<<endl<<endl;
            }
        }
        else
        {
            cout<<endl<<"Game over"<<endl
                <<endl<<"Hit ENTER key to terminate program";
            getline(cin, termination);
            
            return 0;
        }
    }while (!game.isOver());
    
    game.print();
    
    getline(cin, termination);
   
    return 0;
}

char getValidInput()
{
    string line;
    while (line.empty())
    {
        cout << "Next? ";
        getline(cin, line);
        
        if (line.empty())
        {
            continue;
        }

        if(line[0] >= 'A' && line[0] <= 'Z')
        {
            line[0] = line[0] - 'A' + 'a';
        }

        switch (line[0])
        {
            case 'q':
            case 'n':
            case 's':
            case 'e':
            case 'w':
            case '.': break;
            default: line = ""; break;
        }
    }
    
    assert(!line.empty());
    
    return line[0];
}

