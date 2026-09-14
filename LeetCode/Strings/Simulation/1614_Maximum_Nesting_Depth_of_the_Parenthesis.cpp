#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = INT_MIN;
        int currDepth = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') currDepth++;

            maxDepth = max(maxDepth, currDepth);

            if(s[i] == ')') currDepth--;
        }

        return maxDepth;
    }
};

// Technique:
// Simulation

// Approach:
// Traverse the string and maintain the
// current nesting depth of parentheses.
// Increase the depth when encountering '('
// and decrease it when encountering ')'.
// Track the maximum depth reached during
// the traversal and return it at the end.

// TC: O(N)
// N => Length of the string

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}