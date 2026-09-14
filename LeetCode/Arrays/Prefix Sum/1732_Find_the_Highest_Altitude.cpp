#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt  = 0;
        int high = 0;

        for(int inc : gain){
            alt += inc;

            high = max(high, alt);
        }

        return high;
    }
};

// Technique:
// Prefix Sum

// Approach:
// Start from altitude 0.
// Traverse the gain array and continuously
// update the current altitude.
// Track the maximum altitude reached
// during the journey.
// Return the highest altitude encountered.

// TC: O(N)
// N => Number of gain values

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}