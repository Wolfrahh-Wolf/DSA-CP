#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size(); 
        int col0 = 1; 

        // Finding the Rows and Coloums that should be marked Zero
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // <=== TRICKY ===>
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; //Marking i-th Row

                    if( j != 0) matrix[0][j] = 0; //Marking j-th Row
                    else col0 = 0;
                }
            }
        }

        // Marking Zeros
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        //Marking Zeroes on 0th Coloumn
        if(matrix[0][0] == 0){ 
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        
        //Marking Zeroes on 0th Row
        if(col0 == 0){ //Marking Zeroes on 0th Row
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};

// Technique:
// Matrix Traversal + In-Place Marking

// Approach:
// Use the first row and first column
// as marker arrays to avoid extra space.
//
// First Pass:
// Traverse the matrix.
// Whenever a 0 is found:
// - Mark its row by setting matrix[i][0] = 0.
// - Mark its column by setting matrix[0][j] = 0.
// - Use a separate variable (col0)
//   to track whether the first column
//   should be zeroed.
//
// Second Pass:
// Traverse the matrix excluding
// the first row and first column.
// If the corresponding row marker
// or column marker is 0,
// set the current cell to 0.
//
// Finally:
// - Zero the first row if matrix[0][0] == 0.
// - Zero the first column if col0 == 0.
//
// This reuses the matrix itself
// for marking and avoids extra storage.

// TC: O(N × M)
// N => Number of rows
// M => Number of columns

// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}