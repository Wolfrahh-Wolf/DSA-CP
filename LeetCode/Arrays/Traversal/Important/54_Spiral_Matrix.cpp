#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1; // Col No
        int top = 0;
        int bottom = matrix.size() - 1; // Row No

        vector<int> ans;

        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }

            top++;

            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }

            right--;

            if(top <= bottom){
                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }

                bottom--;
            }

            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                
                left++;
            }
        }
        return ans;
    }
};

// Technique:
// Boundary Method/Peeling Layers
// Multi-Pointers => Four-Pointers

// Approach: Iterate over the matrix edges in a spiral order using four pointers (top, bottom, left, right).
// Traversals
// i) Right across the Top Row
// ii) Down across the Right Column
// iii) Left across the Bottom RoW
// iv) Top the Left Column
// Shrinking the boundaries after each step. Repeat until all elements are traversed.

// TC: O(M*N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}