#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    static bool comparator(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comparator);

        int cnt = 1;
        int limit = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= limit){
                cnt++;
                limit = intervals[i][1];
            }
        }

        return n - cnt;
    }
};

// Technique:
// Greedy
// Sorting

// Approach:
// Sort all intervals in ascending
// order of their end times.
//
// Select the first interval and
// keep track of its ending time.
//
// Traverse the remaining intervals.
// If the current interval starts
// after or at the end of the last
// selected interval, keep it and
// update the ending time.
//
// The minimum number of intervals
// to remove is the total number of
// intervals minus the number of
// selected non-overlapping
// intervals.

// TC: O(N log N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}