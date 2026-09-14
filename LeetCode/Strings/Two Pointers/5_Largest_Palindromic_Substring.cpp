#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int expandFromCenter(const string& s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left - 1;
        // Minus 1, since after the while loop, left and right have moved one step beyond the palindrome
    }

public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;

        for(int center = 0; center < s.size(); center++){

            int oddLen = expandFromCenter(s, center, center);

            int evenLen = expandFromCenter(s, center, center + 1);

            int maxLen = max(oddLen, evenLen);

            if(maxLen > end - start){
                start = center - (maxLen - 1) / 2;
                end = center + maxLen / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

// Technique:
// Expand Around Center
// Pointers

// Approach:
// Every palindrome is centered around either:
// - A single character (Odd Length)
// - Two consecutive characters (Even Length)
//
// Treat each index as a potential center
// and expand outward while the characters match.
// Compute the longest odd-length and even-length
// palindrome for every center.
// Track the starting and ending indices of the
// longest palindrome encountered.
// Return the corresponding substring.

// TC: O(N²)
// N => Length of the string
// O(N) centers × O(N) expansion in worst case

// SC: O(1)

// Verdict: Optimal (Without Manacher's Algorithm)

int main(){
    // Main Function placeholder for testing
    return 0;
}