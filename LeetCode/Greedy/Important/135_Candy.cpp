#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int candy(vector<int>& ratings){
        int n = ratings.size();

        int i = 1;
        int candies = 1;

        while(i < n){
            if(ratings[i] == ratings[i - 1]){
                candies += 1; 
                i++;
                continue;
            }

            int peak = 1;

            while(i < n && ratings[i] > ratings[i - 1]){
                i++;
                peak++;
                candies += peak;
            }

            int down = 1;

            while(i < n && ratings[i] < ratings[i - 1]){
                candies += down;
                i++;
                down++;
            }

            if(down > peak){
                candies += (down - peak);
            }
        }

        return candies;
    }
};

// Technique:
// Greedy

// Approach:
// Traverse the ratings while
// identifying increasing, decreasing
// and equal rating sequences.
//
// Assign increasing candies during
// an uphill slope and decreasing
// candies during a downhill slope.
//
// If the downhill sequence becomes
// longer than the preceding uphill
// sequence, compensate the peak
// child with the required extra
// candies.
//
// Accumulate the candies assigned
// to every child throughout the
// traversal.

// TC: O(N)

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}