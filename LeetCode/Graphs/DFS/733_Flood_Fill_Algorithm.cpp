#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private: 
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int row, int col, int &m, int &n){
        if(row < 0 || row >= m) return false;
        if(col < 0 || col >= n) return false;

        return true;
    }

    void dfs(int row, int col, int newColor, int iniColor, 
             vector<vector<int>> &image, vector<vector<int>> &ans){

        ans[row][col] = newColor;

        int m = ans.size();
        int n = ans[0].size();

        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(isValid(nRow, nCol, m, n) &&
               image[nRow][nCol] == iniColor &&
               ans[nRow][nCol] != newColor){
                
                dfs(nRow, nCol, newColor, iniColor, image, ans);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor){

        int iniColor = image[sr][sc];

        vector<vector<int>> ans = image;

        dfs(sr, sc, newColor, iniColor, image, ans);

        return ans;
    }
};

// Technique:
// DFS
// Graph Traversal

// Approach:
// Treat the image as a grid graph.
//
// Start DFS from the source cell and
// change its color to the new color.
//
// Recursively visit all four adjacent
// cells that have the same initial
// color.
//
// Use the result matrix to avoid
// revisiting already colored cells.

// TC: O(M × N)
// Each cell is visited at most once.

// SC: O(M × N) + O(M × N)
// Auxiliary: O(M * N) => Recursive Stack Space
// Copy: O(M * N) => Output matrix 

// Verdict: Optimal


int main(){
    // Main Function placeholder for testing
    return 0;
}