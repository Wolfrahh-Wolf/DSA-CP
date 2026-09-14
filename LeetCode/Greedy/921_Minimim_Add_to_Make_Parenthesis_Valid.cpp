#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open  = 0;
        int close = 0;

        for(char ch : s){
            if(ch == '(') open++;
            else if(ch == ')' && open > 0) open--;
            else close++;
        }

        return open + close;
    }
};

// Technique:
// Greedy

// Approach:
// Traverse the string once.
//
// Count unmatched opening
// parentheses.
//
// Match a closing parenthesis with
// an available opening parenthesis.
//
// Count unmatched closing
// parentheses.
//
// Return the total unmatched
// opening and closing parentheses.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}