#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        
        string left  = s.substr(0, n/2);
        sort(left.begin(), left.end());

        string right = left;
        reverse(right.begin(), right.end());

        if(n & 1) return left + s[n/2] + right;

        return left + right;
    }
};

// Technique:
// Greedy
// Sorting
// Two Pointers

// Approach:
// Extract the left half of the
// palindrome and sort it in
// ascending order to obtain the
// lexicographically smallest
// arrangement.
//
// Mirror the sorted left half to
// form the right half. If the
// string length is odd, keep the
// middle character unchanged and
// place it between the two halves.

// TC: O(N log N)

// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}