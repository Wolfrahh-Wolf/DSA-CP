#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long solve(vector<int>& bt){
        sort(bt.begin(), bt.end());

        long long currWaitTime = 0;
        long long totalWait = 0;

        int n = bt.size();

        for(int i = 1; i < n; i++){
            currWaitTime += bt[i - 1];
            totalWait += currWaitTime;
        }

        return totalWait / n;
    }
};
// Technique:
// Greedy
// Sorting (Shortest Job First)

// Approach:
// Sort all burst times in
// ascending order to execute the
// shortest jobs first.
//
// Maintain the cumulative waiting
// time of the current process and
// add it to the total waiting time.
//
// Return the average waiting time
// of all the processes.

// TC: O(N log N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}