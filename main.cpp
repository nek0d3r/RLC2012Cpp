/******************************************
* Contestant #: 04-0207-0001
* Program's current functionality: You can only move your piece, the opponent cannot move.
*                                  Attempted to make it so you can skip over opponent, but ran out of time.
******************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // 2D int array represents checkerboard. 0 is empty, 1 is you, 2 is opponent.
    int board[8][8] = { {0, 2, 0, 2, 0, 2, 0, 2},
                        {2, 0, 2, 0, 2, 0, 2, 0},
                        {0, 2, 0, 2, 0, 2, 0, 2},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1, 0, 1, 0},
                        {0, 1, 0, 1, 0, 1, 0, 1},
                        {1, 0, 1, 0, 1, 0, 1, 0} };
    
    // Start coordinates for piece to move
    int startX = 0, startY = 0;
    // Coordinates for piece to move to
    int nextX = 0, nextY = 0;
    
    do
    {
        // Outputs checkerboard to the screen
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                    cout << board[i][j];
                    if(j != 7)
                    {
                         cout << ", ";
                    }
            }
            cout << endl;
        }
        cout << endl;
        
        do
        {
             // Ask for coordinates
            cout << "X coordinate of checker to move (or 0 to exit): ";
            cin >> startX;
            
            cout << "Y coordinate of checker to move (or 0 to exit): ";
            cin >> startY;
            
            // If invalid, display error
            if(!(startX >= 0 && startX <= 8 && startY >= 0 && startY <= 8))
                        cout << "(" << startX << ", " << startY << ") is an invalid coordinate. Try again." << endl;
            
            if(startX >= 0 && startX <= 8 && startY >= 0 && startY <= 8)
            {
                      if(board[startY - 1][startX - 1] == 0)
                                     cout << "There is no piece there. Try again." << endl;
                      
                      else if(board[startY - 1][startX - 1] == 2)
                           cout << "That piece belongs to the opponent. Try again." << endl;
            }
        }
        while(!(startX >= 0 && startX <= 8 && startY >= 0 && startY <= 8) || (startX != 0 && startY != 0 && board[startY - 1][startX - 1] != 1));
        
        if(startX != 0 && startY != 0)
        {
                  do
                  {
                       // Ask for coordinates
                       cout << "X coordinate of space to move to: ";
                       cin >> nextX;
                       
                       cout << "Y coordinate of space to move to: ";
                       cin >> nextY;
                       
                       // If invalid, display error
                       if(!(nextX >= 1 && nextX <= 8 && nextY >= 1 && nextY <= 8))
                                  cout << "(" << nextX << ", " << nextY << ") is an invalid coordinate. Try again." << endl;
                       if(nextX >= 1 && nextX <= 8 && nextY >= 1 && nextY <= 8)
                       {
                                if(!((nextX == startX - 1 || nextX == startX + 1) && nextY == startY - 1) || board[nextY - 1][nextX - 1] != 0)
                                            cout << "You cannot move the piece there. Try again." << endl;
                       }
                  }
                  while(!(nextX >= 1 && nextX <= 8 && nextY >= 1 && nextY <= 8) || (!((nextX == startX - 1 || nextX == startX + 1) && nextY == startY - 1) && !((nextX == startX - 2 || nextX == startX - 2) && nextY == startY - 2)) || board[nextY - 1][nextX - 1] != 0);
                  
                  // Move piece
                  board[startY - 1][startX - 1] = 0;
                  board[nextY - 1][nextX - 1] = 1;
        }
    }
    while(startX != 0 && startY != 0);
    
    exit(0);
}
