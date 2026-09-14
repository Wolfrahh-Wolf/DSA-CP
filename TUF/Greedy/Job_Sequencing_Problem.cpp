#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    static bool comparator(const vector<int> &a, const vector<int> &b){
        return a[2] > b[2];
    }

public:  
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        sort(Jobs.begin(), Jobs.end(), comparator);

        int maxDeadline = -1;

        for(int i = 0; i < Jobs.size(); i++){
            maxDeadline = max(maxDeadline, Jobs[i][1]);
        }

        vector<int> hash (maxDeadline, -1);

        int cnt = 0;
        int profit = 0;

        for(int i = 0; i < Jobs.size(); i++){
            for(int j = Jobs[i][1] - 1; j >= 0; j--){
                if(hash[j] == -1){
                    hash[j] = i;
                    cnt++;
                    profit += Jobs[i][2];

                    break;
                }
            }
        }

        return {cnt, profit};
    } 
};

// Technique:
// Greedy
// Sorting

// Approach:
// Sort jobs in descending order
// of profit.
//
// For each job, try to schedule it
// in the latest available slot
// before its deadline.
//
// Scheduling a job as late as
// possible preserves earlier slots
// for jobs with smaller deadlines.
//
// Count the scheduled jobs and
// accumulate their profits.

// TC: O(N log N + N × D)
// D = Maximum Deadline

// SC: O(D)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}