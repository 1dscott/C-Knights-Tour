/**************************************************************************
*Knights tour 8x8
*************************************************************************/

#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <iomanip.h>


int main()
{	
	//12x12 board size apron
	//set board size
	const int boardSize = 12;
	
	//set all values on the chess board to 0
	int board [boardSize][boardSize] = { 
										{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, 
										{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
										{-1,-1,0,0,0,0,0,0,0,0,-1,-1},					
										{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
										{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
										{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
										{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
										{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
										{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
										{-1,-1,0,0,0,0,0,0,0,0,-1,-1},
										{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
										{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
										};
	
	//Arrays of allowed moves 
	int row[] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int col[] = { 1, 2,  2,  1, -1, -2, -2, -1 };							   
						  
	int startingRow;
	int startingColum;
	int count = 0;
	int movesCount;
	int rowCurrent;
	int columCurrent;
	int totalMoves;
	bool canStillMove = true;	
	
	//enter starting row
	cout << "Enter the starting row: ";
    cin  >> startingRow;	
	
	//enter starting colum
    cout << "Enter the starting colum: ";
    cin  >> startingColum;
	cout << endl << endl;
	cout << "Starting Position " << endl;	
	
	//to get the starting 1,1 position add +1 to each number
	startingRow = startingRow + 1;
	startingColum = startingColum +1;
	//start count to track our movement order
	count = count+1;
	
	//make our starting position on the board
	board[startingRow][startingColum] = count;		
	
	//print board with first cord
	for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
			if(board[i][j]>-1)
			{
            std::cout << setw(3) <<board[i][j] << " ";
			}
        }
        std::cout << std::endl;
    }		

	while(totalMoves < 64)
	{
		//Go through all possible moves = 64;
		if(canStillMove == true)
		{	
			//keep track of 64 total possible moves
			totalMoves = totalMoves+1;
			
			//reset our movesCount each loop
			movesCount = 0;
			
			//reset our starting position
			rowCurrent = startingRow;
			columCurrent = startingColum;

			for (int f = 0; f < 8; f++)
			{				
				//keep track of all possible knights move
				movesCount = movesCount+1;
				
				//update our current position with valid move 
				rowCurrent = rowCurrent + row[f];
				columCurrent = columCurrent + col[f];
				
				//if the new move is not outside the board or has not been visited yet.
				if(board[rowCurrent][columCurrent] == 0)  //&& startingColum >= 2 && startingColum <= 10 && rowCurrent >= 2 && rowCurrent <= 10
				{				
					//keep track of movement number
					count = count+1;
					
					//move to new spot and set spot to visited					
					board[rowCurrent][columCurrent] = count;
					canStillMove == true;
					
					//reset our starting coordinate to our current location
					startingRow = rowCurrent;
					startingColum = columCurrent;									
				}
				
				//if we reach all 8 possible move combinations and haven't moved we reach the end
				if (movesCount > 7)
				{
					canStillMove == false;											
				}
			}
		}
	}
			
	//print the final board
	cout << endl << endl;	
	cout << "Complete Knights Tour" << endl;
	
	for (int x = 0; x < boardSize; x++)
    {
        for (int a = 0; a < boardSize; a++)
        {
			if(board[x][a]>-1)
			{
            std::cout << setw(3) << board[x][a] << " ";
			}
        }
        std::cout << std::endl;
    }

}