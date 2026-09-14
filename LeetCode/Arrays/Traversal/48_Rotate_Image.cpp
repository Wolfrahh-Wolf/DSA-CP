#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Diagonal Swappping of Elements
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Row wise Reversal
        for(int i = 0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Technique:
// Transpose of the Matrix
// Row-wise Reversal

// Approach: Transpose the matrix by swapping elements symmetrically across the diagonal,
// then reverse each row to achieve a 90-degree clockwise rotation.

// TC: O(N^2)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}