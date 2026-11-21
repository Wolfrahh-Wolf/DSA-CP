#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries){
        sort(logs.begin(), logs.end(), comparator);

        vector<pair<int, int>> sortedQueries;

        for(int i = 0; i < queries.size(); i++){
            sortedQueries.push_back({queries[i], i});
                      // .emplace_back(queries[i], i);
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(queries.size(), 0);

        unordered_map<int, int> freq;

        int left = 0, right = 0;
        int activeServers = 0;

        for(auto& it : sortedQueries){
            int idx = it.second;
            int st  = max(it.first - x, 0);
            int end = it.first;

            // Window keeps on move towrds RHS even on shrinking, 
            // as the quries are sorted in ascedning order.
                                      // timeStamp <= end 
            while(right < logs.size() && logs[right][1] <= end){
                int server = logs[right][0];

                if(freq[server] == 0) activeServers++;

                freq[server]++;
                right++;
            }

                                     // timeStamp < start
            while(left < logs.size() && logs[left][1] < st){
                int server = logs[left][0];

                freq[server]--;

                if(freq[server] == 0) activeServers--;

                left++;
            }

            ans[idx] = n - activeServers;
        }

        return ans;
    }
};

// Technique:
// Sorting
// Sliding Window
// Two Pointers
// Hash Map

// Approach:
// Sort the logs by timestamp and sort the queries
// while maintaining their original indices.
//
// For each query, determine the time window
// [query - x, query].
//
// Expand the right pointer to include logs
// whose timestamps are <= query.
//
// Shrink the left pointer to exclude logs
// whose timestamps are < query - x.
//
// Maintain the frequency of each server in the
// current window and track the number of active servers.
//
// The answer is the total number of servers
// minus the number of active servers.
//
// Restore the original query order using indices.

// TC: O(L log L + Q log Q + L + Q) => O(L log L + Q log Q)

// O(L log L) => Sort Logs
// O(Q log Q) => Sort Queries
// O(L) => Sliding Window Traversal
// O(Q) => Construct Answer Array

// SC: O(L + Q + N)

// O(L) => Sorted Logs (In-place Sorting)
// O(Q) => Sorted Queries + Answer Array
// O(N) => Frequency Hash Map

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}