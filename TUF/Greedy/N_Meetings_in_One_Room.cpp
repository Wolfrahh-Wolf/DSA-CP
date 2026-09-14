#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:   
    // NOTE
    static bool comparator(const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    }

public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        vector<pair<int, int>> meets;

        int n = start.size();

        for(int i = 0 ; i < n; i++){
            meets.push_back({start[i], end[i]});
        }

        sort(meets.begin(), meets.end(), comparator);

        int cnt = 1;

        int limit = meets[0].second;

        for(int i = 1; i < n; i++){
            if(limit < meets[i].first ){
                cnt++;
                limit = meets[i].second;
            }      
        }

        return cnt;
    }
};

// Technique:
// Greedy
// Sorting

// Approach:
// Store every meeting as a pair of
// {start time, end time}.
//
// Sort all meetings in ascending
// order of their end times.
//
// Select the first meeting and
// keep track of its ending time.
//
// Traverse the remaining meetings.
// If a meeting starts after the
// last selected meeting ends,
// attend it and update the ending
// time.

// TC: O(N log N)

// SC: O(N)

// Verdict: OptimalWW

int main(){
    // Main Function placeholder for testing
    return 0;
}