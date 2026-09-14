#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int &row, int &col, int &m, int &n){
        if(row < 0 || row >= m) return false;
        if(col < 0 || col >= n) return false;

        return true;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dis(m, vector<int>(n, 0));
        
        queue<pair<pair<int, int>, int>> q;


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});                    
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;

            int steps = it.second;

            dis[row][col] = steps;
            
            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(isValid(nRow, nCol, m, n) && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps + 1});
                }
            }
        }

        return dis;
    }
};

// Technique:
// Multi-Source BFS
// Shortest Path in Grid

// Approach:
// Start BFS simultaneously from
// all cells containing 0, with
// distance 0.
//
// For every cell, explore its four
// neighbouring cells.
//
// The first time a cell is visited,
// it is reached through the nearest
// 0, so store the current BFS level
// as its minimum distance.
//
// Use `vis` to ensure each cell is
// processed only once.

// TC: O(M × N)
// Each cell is visited once.

// SC: O(M × N)
// Visited + distance matrices + queue.

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}