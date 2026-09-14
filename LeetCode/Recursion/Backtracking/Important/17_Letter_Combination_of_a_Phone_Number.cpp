#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void func(int idx, string s, string digits, vector<string> &ans, string combos[]){
        if(idx == digits.size()){
            ans.push_back(s);
            return;
        }

        int digit = digits[idx] - '0';
        for(int i = 0; i < combos[digit].size(); i++){
            func(idx+1, s + combos[digit][i], digits, ans, combos);
        }
    }

public:
    vector<string> letterCombinations(string digits){
        vector<string> ans;
        string s = "";
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        func(0, s, digits, ans, combos);
        return ans;
    }
};

// Technique:
// Backtracking (Recursive String Building)

// Approach:
// Use recursion to build all possible letter combinations
// based on digit-to-character mapping.
// For each digit, iterate through its mapped characters
// and append one character at a time.
// When the index reaches the end of the digits string,
// store the formed combination.
// This explores all possible combinations depth-first.

// TC: O(4^N * N)
// N => Length of Digits String
// O(4^N) => Maximum Combinations (since max 4 letters per digit)
// O(N) => Sting Each Combination in Ans
// SC: O(N)
// N => Recursive Stack + Current String Construction

// Verdict: Optimal


int main()
{
    // Main Function placeholder for testing
    return 0;
}