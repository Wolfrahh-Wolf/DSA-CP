#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalRows = matrix.size();
        int col = matrix[0].size() - 1;
        int row = 0;

        while(row < totalRows && col >= 0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
      
        return false;
    }
};

// Technique:
// BS - Binary Search => Staircase Search (Top-Right Traversal in Sorted Matrix)

// Approach:
// Start from top-right element (row = 0, col = last).
// If current == target → return true.
// If current > target → move left (col--), as all below are larger.
// If current < target → move down (row++), as all left are smaller.
// Each step eliminates a full row or column, leveraging row-wise and column-wise sorted property.

// TC: O(rows + cols)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}