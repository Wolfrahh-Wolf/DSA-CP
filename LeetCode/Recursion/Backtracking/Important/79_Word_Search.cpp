#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool recursiveCheck(int i, int j, int idx, vector<vector<char>>& board, string& word){
        bool ans = false;

        if(word.size() == idx) return true;

        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size() ||
           board[i][j] != word[idx] ||
           board[i][j] == '#') return false;

        char x = board[i][j];
        board[i][j] = '#';

        ans |= recursiveCheck(i-1, j, idx+1, board, word);
        ans |= recursiveCheck(i+1, j, idx+1, board, word);
        ans |= recursiveCheck(i, j-1, idx+1, board, word);
        ans |= recursiveCheck(i, j+1, idx+1, board, word);

        board[i][j] = x;

        return ans;
    }

public:
    bool exist(vector<vector<char>> &board, string &word){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(recursiveCheck(i, j, 0, board, word)) return true;
                }
            }
        }

        return false;
    }
};

// Technique:
// Backtracking (DFS on Grid)

// Approach:
// Traverse each cell as a starting point.
// Use DFS to explore 4 directions while matching characters sequentially.
// Mark the current cell as visited and restore it after recursion.
// If all characters are matched, return true.
// Stop exploring a path immediately if mismatch occurs.

// TC: O(Rows * Cols * 3^L)
// L => Length of the word
// SC: O(L)
// L => Recursive Stack Depth

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}