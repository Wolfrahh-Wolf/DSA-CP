#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> getRow(int rowIndex){
        int row = rowIndex + 1;

        vector<int> ans(row);

        ans[0] = 1;

        for(int col = 1; col < row; col++){
            ans[col] = (1LL * ans[col - 1] * (row - col)) / col;
        }

        return ans;
    }
};

// Technique:
// Mathematics (Binomial Coefficient)

// Approach:
// The elements of a Pascal Triangle row
// correspond to binomial coefficients.
//
// nCr = nC(r-1) × (n-r+1) / r
//
// Start with the first element as 1.
// Generate each subsequent element
// using the previous coefficient,
// avoiding factorial computations.
// Store all coefficients of the row
// and return the result.

// TC: O(R)
// R => Number of elements in the row

// SC: O(R)
// R => Output row storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}