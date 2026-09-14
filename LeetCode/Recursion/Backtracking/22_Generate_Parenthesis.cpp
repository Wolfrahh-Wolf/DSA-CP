#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void genParenthesis(int ind, string strr, int open, int close, vector<string> &ans, int n){
        if(open + close == 2*n && open == close){
            ans.push_back(strr);
            return;
        }

        if(open < n)     genParenthesis(ind+1, strr + "(", open + 1, close, ans, n);
        if(open > close) genParenthesis(ind+1, strr + ")", open, close + 1, ans, n);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        genParenthesis(1, "", 0, 0, ans, n);

        return ans;
    }
};

// Technique: Backtracking

// Approach:
// Build the string step by step by choosing either '(' or ')'.
// Add '(' only if the count of open brackets is less than n.
// Add ')' only if it does not exceed the number of open brackets,
// ensuring the sequence is always valid.
// When the total length reaches 2*n and open == close,
// a valid parenthesis combination is formed and added to the answer.

// TC: O(4^N / sqrt(N)) => Catalan Number of Valid Combinations
// SC: O(2N) => Recursive Stack -> O(N) + Temporary String -> O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}