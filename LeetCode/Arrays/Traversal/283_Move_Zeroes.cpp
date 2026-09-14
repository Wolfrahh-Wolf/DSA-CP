#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prevZero = -1; 
        int n = nums.size();
    
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                prevZero = i;
                break;
            }
        }

        if(prevZero == -1) return;

        for(int i = prevZero+1; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[prevZero]);
                prevZero++;
            }
        }
        return;
    }
};

// Technique:
// Two-Pointer Approach (In-Place Partitioning)
// Approach: Find the first occurence of Zero in the Array. Swap this Zero with Non-Zero Element in the upcoming indicies of the Array

// TC: O(N) ==> O(X) + O(N-X) ≈ O(N) 
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}