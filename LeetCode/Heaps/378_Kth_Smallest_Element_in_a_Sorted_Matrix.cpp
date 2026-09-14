#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int cntLessEqual(vector<vector<int>>& matrix, int target){
        int cnt = 0;

        int n = matrix.size();
        int row = n - 1;
        int col = 0;

        while(row >= 0 && col < n){
            if(matrix[row][col] <= target){
                cnt += row + 1;
                col++;
            }
            else row--;
        }

        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k){
        int n = matrix.size();

        int low  = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while(low < high){
            int mid = low + (high - low) / 2;

            if(cntLessEqual(matrix, mid) < k) low = mid + 1; // NOTE
            else high = mid; // NOTE
        }

        return low;
    }
};

// Technique:
// Binary Search
// Matrix Traversal

// Approach:
// Perform binary search on the
// value range of the matrix.
//
// For each middle value, count the
// number of elements less than or
// equal to it.
//
// Narrow the search space based on
// whether the count is smaller than
// K.
//
// Return the smallest value whose
// count is at least K.

// TC: O(N log(Max - Min))
// N => No of Rows/Columns

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}