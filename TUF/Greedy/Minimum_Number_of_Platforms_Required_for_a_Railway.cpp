#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n = Arrival.size();

        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int maxPlatform = 1;
        int platform = 1;

        int limit = Departure[0];
        int i = 1; 
        int j = 0;

        while(i < n && j < n){
            if(Arrival[i] <= Departure[j]){
                platform++;
                i++;
            }
            else{
                platform--;
                j++;
            }
            
            maxPlatform = max(maxPlatform, platform);
        }
        
        return maxPlatform;
    }
};

// Technique:
// Greedy
// Sorting
// Two Pointers

// Approach:
// Sort the arrival and departure
// times independently.
//
// Traverse both arrays using two
// pointers.
//
// If the next train arrives before
// or at the earliest departure,
// allocate a new platform.
//
// Otherwise, free a platform by
// moving to the next departure.
//
// Track the maximum number of
// platforms required at any point.

// TC: O(N log N)
// SC: O(1)

// Verdict: Optimal


int main(){
    // Main Function placeholder for testing
    return 0;
}