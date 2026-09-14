#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;

        ansRow.push_back(1);

        for(int col = 1; col < row; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }

        return ansRow;
    }

public:
    vector<vector<int>> pascalTriangleIII(int n){
        vector<vector<int>> pascalTriangle;

        for(int row = 1; row <= n; row++){
            pascalTriangle.push_back(generateRow(row));
        }

        return pascalTriangle;
    }
};

// Technique:
// Mathematics (Binomial Coefficient)

// Approach:
// Generate Pascal's Triangle row by row.
// For each row, start with the first element as 1.
// Use the relation between consecutive
// binomial coefficients to compute the next element:
//
// nCr = nC(r-1) × (n-r+1) / r
//
// This avoids factorial computations.
// Generate every row independently
// and store it in the final Pascal Triangle.
// Return the completed triangle.

// TC: O(N²)
// O(1 + 2 + 3 + ... + N) = O(N²)
// N => Number of rows

// SC: O(N²)
// N² => Storage for all elements
// in Pascal's Triangle

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}