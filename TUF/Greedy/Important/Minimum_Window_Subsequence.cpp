#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string minWindow(string s1, string s2){
        int n = s1.size();
        int m = s2.size();

        string ans = "";

        unordered_map<char, vector<int>> indices;

        for(int i = 0; i < n; i++){
            indices[s1[i]].push_back(i);
        }

        vector<int> ind(m, 0);

        for(int start = 0; start < n; start++){
            int prev = start - 1;

            for(int j = 0; j < m; j++){
                if(!indices.count(s2[j])) return "";

                const vector<int> &currIndices = indices[s2[j]];

                while(ind[j] < currIndices.size() && currIndices[ind[j]] <= prev){
                    ind[j]++;
                }

                if(ind[j] == currIndices.size()) return ans;

                prev = currIndices[ind[j]];
            }

            if(ans.empty() || prev - start + 1 < ans.size()){
                ans = s1.substr(start, prev - start + 1);
            }
        }

        return ans;
    }
};

// Technique:
// Greedy
// Binary Search
// Hashing

// Approach:
// Store the indices of every character
// in the first string using a hash map.
//
// For every possible starting position,
// greedily locate each character of the
// second string in order by advancing
// through its stored indices.
//
// If every character is found, compute
// the current window length and update
// the minimum window if it is smaller.
//
// If any character cannot be found,
// no further valid windows are possible,
// so return the best answer found.

// TC: O(N + M + Total Pointer Moves)
// N => Length of String S1
// M => Length of String S2

// SC: O(N)
// N => Indices Stored in Hash Map

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}