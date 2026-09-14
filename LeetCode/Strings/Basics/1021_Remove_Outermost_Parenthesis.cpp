#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        
        for(char ch : s){
            if (ch == ')' && cnt > 0) cnt--;

            if(cnt > 0) ans += ch;
            
            if(ch == '(') cnt++;
        }

        return ans;
    }
};

// Technique:
// Balance Counter (Primitive Decomposition)

// Approach:
// Use counter to track parentheses balance (depth):
// - Opening '(': cnt++
// - Closing ')': cnt-- (AFTER checking)
// Skip outermost parentheses by adding to result ONLY when:
// - For '(': cnt > 0 (not first '(' of primitive)
// - For ')': cnt > 0 (not closing outermost ')')
// Result contains inner parentheses of all primitive components

// TC: O(N)
// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}