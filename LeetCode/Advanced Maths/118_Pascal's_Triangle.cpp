#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> generateElements(int rows){
        vector<int> elements;
        long long elem = 1;
        elements.push_back(1); // Starting Element of all the Rows

        for(int col = 1; col < rows; col++){
            elem = elem * (rows-col) / col;
            // Expansion of Above Computation
            // elem = elem * (rows-col);
            // elem = elem / col;
            elements.push_back(elem);
        }

        return elements;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int row = 1; row <= numRows; row++){
            ans.push_back(generateElements(row));
        }

        return ans;
        
    }
};

// Technique:
// Binomial Coefficient Formula ==> C(n,k) = C(n,k-1) * (n - k + 1) / k
// Formula => elem = elem * (row - col) / col

// Algorithm:
// Iterative Binomial Coefficient Generation for Pascal’s Triangle.

// Approach
// For each row, calculate the elements directly using the binomial coefficient formula.
// Start with 1, then iteratively compute the next elements using 
// Formula => elem = elem * (row - col) / col
// Build each row and collect all rows to form the complete triangle.

// TC: O(N^2) => Each row takes O(row) operations, total rows is N, so O(N^2)
// SC: O(N^2) => The triangle structure uses O(N^2) space to store all values

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}