#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
const int N=9;
//to print the gridlines
void printGrid(vector<vector<int> >&grid)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
//to check if it is safe to place number in a specific position
bool isSafe(vector<vector<int> >&grid,int row,int col,int num)
{
//for row
for(int i=0;i<N;i++)
{
    if(grid[row][i]==num)
    {
        return false;
    }
}
//for column
for(int i=0;i<N;i++)
{
    if(grid[i][col]==num)
    {
        return false;
    }
}
//check subgrid
int startRow = row-row%3;
int startCol = col-col%3;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        if(grid[i+startRow][j+startCol]==num)
        {
            return false;
        }
    }
}
return true;
}
bool solveSudoku(vector<vector<int> >& grid)
    {
        int row,col;
        bool isEmpty = false;
        for (row = 0; row < N; row++)
            {
              for (col = 0; col < N; col++)
               {
                 if (grid[row][col] == 0)
                 {
                   isEmpty = true;
                    break;
                 }
        }
        if (isEmpty)
        {
            break;
        }
    }

        if (!isEmpty)
        {
        return true;
        }
         for (int num = 1; num <= 9; num++)
            {
        if (isSafe(grid, row, col, num))
            {
            grid[row][col] = num;
            if (solveSudoku(grid))
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}
void generateSudoku(vector<vector<int> >&grid){
    //fill the grid with zeros
    for(int i=0;i<N;i++){
        grid.push_back(vector<int>(N,0));
    }
    //Solve the Sudoku puzzle with a fixed number of starting points
    grid[0][0] = 5;
    grid[0][1] = 3;
    grid[0][4] = 7;
    grid[1][0] = 6;
    grid[1][3] = 1;
    grid[1][4] = 9;
    grid[1][5] = 5;
    grid[2][1] = 9;
    grid[2][2] = 8;
    grid[2][7] = 6;
    grid[3][0] = 8;
    grid[3][4] = 6;
    grid[3][8] = 3;
    grid[4][0] = 4;
    grid[4][3] = 8;
    grid[4][5] = 3;
    grid[4][8] = 1;
    grid[5][0] = 7;
    grid[5][4] = 2;
    grid[5][8] = 6;
    grid[6][1] = 6;
    grid[6][6] = 2;
    grid[6][7] = 8;
    grid[7][3] = 4;
    grid[7][4] = 1;
    grid[7][5] = 9;
    grid[7][8] = 5;
    grid[8][4] = 8;
    grid[8][7] = 7;
    grid[8][8] = 9;

}

int main()
{
    vector<vector<int> >grid;
    generateSudoku(grid);
    printGrid(grid);
    return 0;
}


