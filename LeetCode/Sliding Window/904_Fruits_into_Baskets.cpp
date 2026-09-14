#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int totalFruit(vector<int>& fruits){
        int n = fruits.size();

        unordered_map<int, int> mpp;

        int maxi = INT_MIN;

        int l = 0;
        int r = 0;
    
        while(r < n){
            mpp[fruits[r]]++;


            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);

                l++;
            }
            maxi = max(maxi, r - l + 1);

            r++;
        }

        return maxi;
    }
};

// Technique:
// Sliding Window
// Hashing

// Approach:
// Maintain a sliding window using two
// pointers l and r.
//
// Use a hash map to store the frequency
// of each fruit type in the current window.
//
// Expand the window by moving r and
// include the current fruit.
//
// If the window contains more than two
// distinct fruit types, shrink it from
// the left until only two types remain.
//
// Update the maximum valid window length
// during the traversal.
//
// Return the maximum number of fruits
// that can be collected.

// TC: O(N)
// N => Size of the Array

// SC: O(1)
// At Most 3 Fruit Types Stored in the Hash Map

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}