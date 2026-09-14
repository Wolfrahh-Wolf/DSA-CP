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

    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, queue<pair<int, int>> &q){
        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(isValid(nRow, nCol, m, n) && 
                   !vis[nRow][nCol] &&
                   grid[nRow][nCol] == 1){

                    q.push({nRow, nCol});
                    vis[nRow][nCol] = true;
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid){
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || i == m-1 ||
                    j == 0 || j == n-1) && 
                    grid[i][j] == 1){

                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        bfs(grid, vis, q);

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }

        return cnt;
    }
};

// Technique:
// Multi-Source BFS
// Boundary Traversal

// Approach:
// Start BFS from all boundary land
// cells (`1`) simultaneously.
//
// Mark every land cell connected to
// the boundary as visited.
//
// Finally, count the remaining
// unvisited land cells. These cells
// cannot reach the boundary and are
// therefore enclaves.

// TC: O(M × N)
// Each cell is visited at most once.

// SC: O(M × N)
// Visited matrix + BFS queue.

// Verdict: Optimal


int main(){
    // Main Function placeholder for testing
    return 0;
}