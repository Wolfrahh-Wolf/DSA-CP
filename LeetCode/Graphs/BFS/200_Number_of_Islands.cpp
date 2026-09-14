#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int row, int col, int n, int m){
        if (row < 0 || row >= n) return false;
        if (col < 0 || col >= m) return false;
        
        return true;
    }

    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(isValid(nRow, nCol, n, m) &&
                    !vis[nRow][nCol] && 
                    grid[nRow][nCol] == '1'){

                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;

                    vis[i][j] = 1;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};

// Technique:
// BFS
// Graph Traversal

// Approach:
// Treat every unvisited `1` as the
// starting cell of a new island.
//
// Perform BFS and visit all connected
// `1` cells using 8-directional movement.
//
// Mark every visited land cell to
// prevent counting the same island
// again.
//
// Increment the island count whenever
// a new unvisited land cell is found.

// TC: O(N × M)
// Each cell is visited once.

// SC: O(N × M)
// Visited matrix + BFS queue.

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}