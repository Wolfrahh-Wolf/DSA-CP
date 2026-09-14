#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int n = s.size();

        vector<int> freq(256, 0);

        int len  = 0;
        int low  = 0;

        for(int high = 0; high < n; high++){
            freq[s[high]]++;

            while(freq[s[high]] > 1) freq[s[low++]]--;

            len = max(len, high - low + 1);
        }

        return len;
    }
};

// Technique:
// Sliding Window + Hashing

// Approach:
// Maintain a window containing only unique characters.
// Expand the window using the right pointer.
// Track character frequencies using a hash array.
// If a duplicate character is encountered,
// shrink the window from the left until
// the duplicate is removed.
// Update the maximum window length
// after processing each character.
// Return the length of the longest substring
// containing distinct characters.

// TC: O(N)
// N => Length of the string
// Each character enters and leaves the window at most once

// SC: O(1)
// Constant-sized frequency array (256 characters)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}