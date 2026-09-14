#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:   
    int rowWithMax1s(vector < vector < int >> & mat) {
        int totalRows = mat.size();

        int row = 0;
        int col = mat[0].size() - 1;
        
        int ansRow = -1;

        while(row < totalRows && col >= 0){
            if(mat[row][col] == 1){
                ansRow = row;
                col--;
            }
            else row++;
        }

        return ansRow;
    }
};

// Technique: 
// BS - Staircase Binary Search (Modified Binary Search)

// Approach:
// Start from top-right corner of matrix
// - If 1 found: move left (more 1s possible in same row)
// - If 0 found: move down (need higher row for 1s)
// First row where we find 1s has maximum leading 1s

// TC: O(rows + cols)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}