/*

Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true

*/


#include<bits/stdc++.h>
using namespace std;


bool isPossible(int** board, int row, int col, int num)
{
    // Checking row wise
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == num)
        {
            return false;
        }
    }
    
    // Checking column wise
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }
    
    // Checking box wise
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[rowFactor + i][colFactor + j] == num)
            {
                return false;
            }
        }
    }
    
    return true;
}


bool find_empty(int** board, int &row, int &col)
{   
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                
                return true;
            }
        }
    }
    
    return false;
}


bool sudoku_solver(int** board)
{
    int row, col;
    
    if (!find_empty(board, row, col))
    {
        return true;
    }
    
    for (int i = 1; i <= 9; i++)
    {
        if (isPossible(board, row, col, i))
        {
            board[row][col] = i;
            
            if (sudoku_solver(board))
            {
                return true;
            }
            
            board[row][col] = 0;
        }
    }
    
    return false;
}


int main()
{
    int** board = new int*[9];
    
    for (int i = 0; i < 9; i++)
    {
        board[i] = new int[9];
    }
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    
    bool res = sudoku_solver(board);
    
    if (res == false)
    {
        cout << endl << "false" << endl << endl;
    }
    
    else
    {
        cout << endl << "true" << endl << endl;
    }

    /*for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;*/
    
    return 0;
}