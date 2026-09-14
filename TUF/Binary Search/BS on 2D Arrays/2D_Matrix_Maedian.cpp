#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int countLessThanEqual(vector<int>&matrix, int median){

        return upper_bound(matrix.begin(), matrix.end(), median) - matrix.begin();
    }

public:
    int findMedian(vector<vector<int>>&matrix) {
        int totalRows = matrix.size();
        int totalCols = matrix[0].size();

        int low  = INT_MAX;
        int high = INT_MIN;

        for(int row = 0; row < totalRows; row++){
            low  = min(low, matrix[row][0]);
            high = max(high, matrix[row][totalCols - 1]);
        }

        while(low <= high){
            int mid = low + (high - low) / 2;

            int lessThanMidCount = 0;

            for(int row = 0; row < totalRows; row++){
                lessThanMidCount += countLessThanEqual(matrix[row], mid);
            }

            if(lessThanMidCount < (totalRows * totalCols + 1) / 2) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
};

// Technique:
// BS - Binary Search on Value Range
// Row-wise Upper Bound Counting

// Approach:
// 1. Find Search Space:
//    low = min(matrix[row][0])
//    high = max(matrix[row][last])
// 2. Binary search for median value:
//    - For candidate mid, count elements ≤ mid across all rows using upper_bound
//    - Target position = (totalRows * totalCols + 1) / 2 (upper median)
// 3. Decision:
//    - lessThanMidCount < target → median in RIGHT half (low = mid + 1)
//    - else → median in LEFT half (high = mid - 1)
// 4. low converges to smallest value where ≥ half elements are ≤ it

// TC: O(totalRows * log(totalCols) * log(high - low))
// O(totalRows * log(totalCols)) => countLessThanEqual();
// O(log(high - low)) => findMedian();
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}