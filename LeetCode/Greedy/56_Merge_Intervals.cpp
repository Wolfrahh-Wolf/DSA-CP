#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> ans;
        // Sorting
        sort(intervals.begin(), intervals.end());

        // Linear Scan
        for(int i = 0; i<intervals.size(); i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                // Merging
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};

// Technique:
// Sorting
// Greedy
// Linear Scan
// In-Place Merging

// Syntax:
// intervals[i][0] => First Sub Element of a Element ==> [x,y] -> Refer x
// intervals[i][1] => Second Sub Element of a Element ==> [x,y] -> Refer y
// intervals[i] => Entire Element ==> [x,y] -> Refer (x,y)

// Approach:
// Sort intervals by start time.
// Iterate over intervals and compare each interval's start with the end of the last merged interval.
// If they overlap, merge by updating the end of the last merged interval to the max end.
// If no overlap, add the current interval as a new merged interval.

// TC: O(N log N) => Sorting
// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}
