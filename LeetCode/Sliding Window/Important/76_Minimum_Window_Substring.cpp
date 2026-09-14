#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t){
        int target = t.size();
        int n = s.size();
        if(target > n) return "";

        int l = 0;
        int r = 0;

        int cnt  = 0;
        int sIdx = -1;
        int len  = INT_MAX;

        unordered_map<char, int> freq;

        for(char ch : t){
            freq[ch]++;
        }

        while(r < n){
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;

            while(cnt == target){
                if(r - l + 1 < len){
                    sIdx = l;
                    len  = r - l + 1;
                }
                
                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt--;

                l++;
            }

            r++;
        }

        if(sIdx == -1) return "";
        return s.substr(sIdx, len);
    }
};

// Technique:
// Sliding Window
// Hashing

// Approach:
// Store the required frequency of each
// character in the target string using
// a hash map.
//
// Maintain a sliding window using two
// pointers l and r.
//
// Expand the window by moving r and
// reduce the required frequency of the
// current character.
//
// Whenever a required character is found,
// increase the matched character count.
//
// Once all characters of the target are
// matched, shrink the window from the
// left while maintaining validity.
//
// During shrinking, update the minimum
// window length and its starting index.
//
// Return the smallest valid substring.
// If no valid window exists, return "".

// TC: O(N + M)
// N => Length of String S
// M => Length of String T

// SC: O(256)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}