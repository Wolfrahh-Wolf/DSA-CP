#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char digit = '1'; digit <= '9'; digit++){
                        if(isValidDigit(board, i, j, digit)){
                            board[i][j] = digit;

                            if(solve(board)) return true;
                            else board[i][j] =  '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidDigit(vector<vector<char>>& board, int row, int col, char digit){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == digit || board[i][col] == digit)
                return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == digit) return false;
            }
        }
        
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// Technique:
// Backtracking (Recursion)

// Approach:
// Traverse the board to find an empty cell '.'.
// Try placing digits from '1' to '9'.
// Check whether the digit is valid in the current row,
// column, and 3x3 subgrid.
// If valid, place the digit and recursively solve the remaining board.
// If no digit works, backtrack by resetting the cell.
// Continue until the entire board is filled correctly.

// TC: O(9^E)
// E => Empty Cells (Worst Case: E = 9)

// SC: O(E)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}