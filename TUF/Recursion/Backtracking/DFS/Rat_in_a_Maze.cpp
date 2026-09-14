#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> result;

class Solution {
public:
    void path(vector<vector<int>>& m, int x, int y, string dir, int n){
        if(x == n - 1 && y == n - 1){
            result.push_back(dir);
            return;
        }

        if(m[x][y] == 0) return;

        m[x][y] = 0;

        if(x > 0) path(m, x - 1, y, dir + 'U', n);
        if(y > 0) path(m, x, y - 1, dir + 'L', n);
        if(x < n - 1) path(m, x + 1, y, dir + 'D', n);
        if(y < n - 1) path(m, x, y + 1, dir + 'R', n);

        m[x][y] = 1;
    }

    vector<string> findPath(vector<vector<int>>& grid){
        int n = grid.size();

        result.clear();

        if(grid[0][0] == 0 || grid[n - 1][n - 1] == 0){
            return result;
        }

        path(grid, 0, 0, "", n);

        sort(result.begin(), result.end());

        return result;
    }
};

// Technique:
// Backtracking + DFS

// Approach:
// Start from the source cell (0, 0)
// and explore all possible directions:
//
// U -> Up
// L -> Left
// D -> Down
// R -> Right
//
// Mark the current cell as visited
// before exploring adjacent cells
// to avoid revisiting the same cell
// within the current path.
//
// Whenever the destination
// (n - 1, n - 1) is reached,
// store the path string.
//
// After exploring all directions,
// unmark the current cell
// to allow it to be used in
// other valid paths.
//
// Finally, sort all generated paths
// and return the result.

// TC: O(4^(N²))
// In the worst case, every cell can
// branch into up to 4 directions

// SC: O(N²)
// Recursive stack + path exploration

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}