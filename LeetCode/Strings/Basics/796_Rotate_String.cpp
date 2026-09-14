#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string doubleS = s + s;

        return doubleS.find(goal) != string::npos;
    }
};

// Technique:
// String Matching

// Approach:
// A valid rotation of a string must appear
// as a substring of the string concatenated
// with itself.
// First, ensure both strings have the same length.
// Create:
//
// s + s
//
// and check whether goal exists as a substring.
// If it exists, goal is a rotation of s;
// otherwise, it is not.

// TC: O(N)
// N => Length of the string

// SC: O(N)
// N => Concatenated string storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}