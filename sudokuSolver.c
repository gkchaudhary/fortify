#include <stdio.h>
#include <stdlib.h>
 
// N is the size of the 2D matrix   N*N
#define N 9

 
/* isValid utility will check whether assignment of num at row & col will be valid or invalid. */

int isValid(int grid[N][N], int row, 
                       int col, int num)
{
     
    /* Check if row has same num then it is a invalid entry */
    
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return 0;
 
    /* Check if col has same num then it is a invalid entry */


    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return 0;
 
    /* Check if subgrid has same num then it is a invalid entry */
    int subRow = row - row % 3;
    int subCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + subRow][j + subCol] == num)
                return 0;
 /* All checks are successful , hence returning 1 as it is a valid entry */
    return 1;
}
 
/* sudokuSolver is the utility which will fill the grid if the 
   grid is valid else it will return 0 for invalid grid  */
int sudokuSolver(int grid[N][N], int row, int col)
{
     
    /* Check if we have reached the last row and last column then 
       return 1 as no more entry to shell to check and fill the value */ 
    if (row == N - 1 && col == N)
        return 1;
 
    /* Check if we are in last column then go to next row */       
    if (col == N) 
    {
        row++;
        col = 0;
    }
   
    /* Check if the current grid position value >0, then we iterate for next column */
    if (grid[row][col] > 0)
        return sudokuSolver(grid, row, col + 1);
 
    for (int num = 1; num <= N; num++) 
    {
         
        /* Check if it is valid to place num at row & col position */
        if (isValid(grid, row, col, num)==1) 
        {

            grid[row][col] = num;
           
            /* Checking for next possibility for next column */
            if (sudokuSolver(grid, row, col + 1)==1)
                return 1;
        }
       
        /* As our assumption was wrong hence making the grid value to 0. */
        grid[row][col] = 0;
    }
    return 0;
}
 
int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 0, 0, 2, 0, 0, 0, 0, 4, 1 },
                       { 0, 0, 0, 0, 8, 2, 0, 7, 0 },
                       { 0, 0, 0, 0, 4, 0, 0, 0, 9 },
                       { 2, 0, 0, 0, 7, 9, 3, 0, 0 },
                       { 0, 1, 0, 0, 0, 0, 0, 8, 0 },
                       { 0, 0, 6, 8, 1, 0, 0, 0, 4 },
                       { 1, 0, 0, 0, 9, 0, 0, 0, 0 },
                       { 0, 6, 0, 4, 3, 0, 0, 0, 0 },
                       { 8, 5, 0, 0, 0, 0, 4, 0, 0 } };
 
    if (sudokuSolver(grid, 0, 0)==1)
    {
	 for (int i = 0; i < N; i++)
      	{
         	for (int j = 0; j < N; j++)
            		printf("%d ",grid[i][j]);
         	printf("\n");
       }
    } 
    else
        printf("No solution exists");
 
    return 0;
}
