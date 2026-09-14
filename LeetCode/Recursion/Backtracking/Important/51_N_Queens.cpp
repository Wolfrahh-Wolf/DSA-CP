#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int r = row, c = col;

        while(r >= 0 && c >= 0){
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row;
        c = col;

        while(r >= 0){
            if (board[r][c] == 'Q') return false;
            r--;
        }

        r = row;
        c = col;

        while(r >= 0 && c < board[0].size()){
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        return true;
    }

    void func(int row, vector<vector<string>>& ans, vector<string>& board){
        if(row == board.size()){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < board[0].size();  col++){
            if(isSafe(board, row, col)){
                board[row][col] = 'Q';
                func(row + 1, ans, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        func(0, ans, board);
        return ans;
    }
};

// Technique:
// Backtracking (Recursion)

// Approach:
// Place queens row by row on the chessboard.
// For each cell, check whether placing a queen is safe
// by verifying upper-left diagonal, upper column,
// and upper-right diagonal.
// If safe, place the queen and recursively solve
// for the next row.
// If no valid placement exists, backtrack by removing the queen.
// Store the board configuration when all queens are placed.

// TC: O(N! * N)
// N! => Possible queen placements
// O(N) => Safety check for each placement
// N => Size of the board

// SC: O(N^2)
// O(N^2) => Board storage
// O(N)   => Recursive stack depth

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}