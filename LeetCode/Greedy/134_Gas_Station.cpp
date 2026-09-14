#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, current = 0, start = 0; 
        int n = gas.size(); 

        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i]; 
            current += gas[i] - cost[i]; 

            if (current < 0) {
                current = 0; 
                start = i + 1; 
            }
        }
        return (total < 0) ? -1 : start;
    }
};

// Technique:
// Greedy

// Approach:
// Track the total gas balance to
// determine whether completing the
// entire circuit is possible.
//
// Maintain the current gas balance
// from the current starting station.
//
// If the current balance becomes
// negative, none of the stations from
// the current start through `i` can
// be a valid starting point.
//
// Therefore, reset the balance and
// choose `i + 1` as the new start.
//
// Finally, if the total gas is less
// than the total cost, completing the
// circuit is impossible.

// TC: O(N)

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}