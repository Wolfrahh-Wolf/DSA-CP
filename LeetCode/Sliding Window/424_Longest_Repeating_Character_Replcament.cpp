#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k){
        vector<int> freq(26, 0);

        int maxFreq = 0;
        int maxLen  = 0;

        int l = 0;
        int r = 0;

        int n = s.size();

        while(r < n){
            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            if((r - l + 1) - maxFreq > k){
                freq[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            cout << l << " " << r << " " << maxLen << endl;
            r++;
        }

        return maxLen;
    }
};

// Technique:
// Sliding Window
// Frequency Counting

// Approach:
// Maintain a sliding window using two
// pointers l and r.
//
// Track the frequency of characters
// within the current window and maintain
// the maximum frequency seen so far.
//
// If the number of replacements required:
//
// Window Length - Maximum Frequency
//
// exceeds K, shrink the window from
// the left.
//
// Update the maximum valid window length
// during the traversal.
//
// Return the maximum length found.

// TC: O(N)
// N => Length of the String

// SC: O(1)
// Frequency Array of Size 26

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}