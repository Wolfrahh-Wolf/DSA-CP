#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValide(int &i, int &j, int &m, int &n){
        if(i < 0 || i >= m) return false;
        if(j < 0 || j >= n) return false;

        return true;
    }

public:
    int orangesRotting(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        int totalOrange = 0;

        int time = 0;
        int cnt  = 0;

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) totalOrange++;

                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty()){
            int k = q.size();

            cnt += k;

            while(k--){
                auto cell = q.front();
                q.pop();

                int row = cell.first;
                int col = cell.second;

                for(int i = 0; i < 4; i++){
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    if(isValide(nRow, nCol, m, n) && grid[nRow][nCol] == 1){
                        grid[nRow][nCol] = 2;
                        q.push({nRow, nCol});
                    }
                }
            }

            if(!q.empty()) time++;
        }

        if(totalOrange == cnt) return time;

        return -1;
       
    }
};

// Technique:
// BFS
// Multi-Source BFS

// Approach:
// Push all initially rotten oranges
// into the queue as starting points.
//
// Process the queue level by level.
// Each level represents one minute.
//
// For every rotten orange, check its
// four adjacent cells. If an adjacent
// orange is fresh, rot it and push it
// into the queue.
//
// Track the total number of oranges
// and the number processed by BFS.
//
// If all oranges become rotten,
// return the elapsed time. Otherwise,
// return -1.

// TC: O(M * N)
// SC: O(M * N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}