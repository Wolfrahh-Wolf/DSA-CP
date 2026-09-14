#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k){
        int n = s.size();

        unordered_map<char, int> freq;

        int l = 0;
        int r = 0;

        int maxLen = INT_MIN;

        while(r < n){
            freq[s[r]]++;

            if(freq.size() > k){
                freq[s[l]]--;
                if(!freq[s[l]]) freq.erase(s[l]);
                l++;
            }

            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};

// Technique:
// Sliding Window
// Hashing

// Approach:
// Maintain a sliding window using two
// pointers l and r.
//
// Use a hash map to store the frequency
// of characters within the current window.
//
// Expand the window by moving r and
// include the current character.
//
// If the number of distinct characters
// exceeds K, shrink the window from the
// left until at most K distinct characters
// remain.
//
// Update the maximum valid window length
// during the traversal.
//
// Return the maximum length found.

// TC: O(N)
// N => Length of the String

// SC: O(K)
// K => Maximum Distinct Characters Stored

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}