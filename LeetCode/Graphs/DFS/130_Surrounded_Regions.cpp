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

    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<bool>> &vis, int m, int n){
        vis[row][col] = true;

        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(isValid(nRow, nCol, m, n) && 
               mat[nRow][nCol] == 'O' &&
               !vis[nRow][nCol]){

                dfs(nRow, nCol, mat, vis, m, n);
               }
        }
    }

public:
    void solve(vector<vector<char>> &mat){
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int j = 0; j < n; j++){
            if(!vis[0][j] && mat[0][j] == 'O')
                dfs(0, j, mat, vis, m, n);
            if(!vis[m-1][j] && mat[m-1][j] == 'O')
                dfs(m-1, j, mat, vis, m, n);
        };

        for(int i = 0; i < m; i++){
            if(!vis[i][0] && mat[i][0] == 'O')
                dfs(i, 0, mat, vis, m, n);
            if(!vis[i][n-1] && mat[i][n-1] == 'O') 
                dfs(i, n-1, mat, vis, m, n);
        }

    
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }
    }
};

// Technique:
// DFS
// Boundary Traversal

// Approach:
// Start DFS from all boundary `O`
// cells and mark every `O` connected
// to the boundary as safe.
//
// Any `O` that remains unvisited
// cannot be connected to the boundary,
// so it is surrounded and can be
// converted to `X`.
//
// Finally, traverse the matrix and
// flip all unvisited `O`s to `X`.

// TC: O(M × N)
// Each cell is visited at most once.

// SC: O(M × N)
// Visited matrix + DFS recursion stack.

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}