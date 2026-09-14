#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(int n, string s, char prev, vector<string> &ans){
        if(s.length() == n){
            ans.push_back(s);
            return;
        }

        backtrack(n, s + "0", '0', ans);
        if(prev != '1'){
            backtrack(n, s + "1", '1', ans);
        }
    }

public:
    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;

        backtrack(n, "", '0', ans);

        return ans; 
    }
};

// Technique:
// Backtracking (Recursive String Construction with Constraint)

// Approach:
// Use recursion to generate binary strings of length n.
// Always allow appending '0'.
// Append '1' only if the previous character was not '1'
// to avoid consecutive ones.
// When the string length reaches n, store it in the result.

// TC: O(2^N)
// N => Length of the binary string
// SC: O(N)
// N => Recursive Stack + Current String Construction

// Verdict: Optimal


int main()
{
    // Main Function placeholder for testing
    return 0;
}