#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxElemIdx(vector<vector<int>>& matrix, int col, int totalRows){
        int maxValue = INT_MIN;
        int maxRowInd;

        for(int i = 0; i < totalRows; i++){
            if(matrix[i][col] > maxValue){
                maxValue = matrix[i][col];
                maxRowInd = i;

            }
        }

        return maxRowInd;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int totalRows = mat.size();
        int totalCols = mat[0].size();
        int low = 0;
        int high = totalCols - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int row = maxElemIdx(mat, mid, totalRows);

            int leftNeighbour  = (mid - 1) >= 0        ? mat[row][mid - 1] : -1;
            int rightNeighbour = (mid + 1) < totalCols ? mat[row][mid + 1] : -1;

            if(mat[row][mid] > leftNeighbour && mat[row][mid] > rightNeighbour) return{row, mid};
            else if(leftNeighbour > mat[row][mid]) high = mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};

    }
};

// Technique:
// Binary Search on Columns + Max Element Scan per Column

// Approach:
// 1. Binary search across COLUMNS (0 to totalCols-1)
// 2. For each mid column, find row with MAXIMUM value using linear scan
// 3. Check if this max element is peak:
//    - Compare with LEFT neighbor (mid-1) and RIGHT neighbor (mid+1)
//    - Use -1 for boundary conditions (smaller than all valid values)
// 4. Decision:
//    - Peak found → return {row, mid}
//    - LEFT neighbor larger → search LEFT half (high = mid-1)
//    - RIGHT neighbor larger → search RIGHT half (low = mid+1)
// 5. Guaranteed to find peak due to matrix properties

// TC: O(totalRows × log(totalCols))
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}