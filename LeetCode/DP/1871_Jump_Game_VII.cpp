#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool canReach(string s, int minJump, int maxJump){
        int n = s.size();

        vector<bool> dp(n);
        dp[0] = true;

        int reachable = 0;

        for(int i = 1; i < n; i++){
            if(i - minJump >= 0 && dp[i - minJump])
                reachable++;

            if(i - maxJump - 1 >= 0 && dp[i - maxJump - 1])
                reachable--;

            dp[i] = s[i] == '0' && reachable > 0;
        }

        return dp[n - 1];
    }
};

// Technique:
// Dynamic Programming
// Sliding Window

// Approach:
// Use DP to track whether each index
// can be reached.
//
// Maintain the number of reachable
// positions within the current jump
// range.
//
// Add the position entering the
// window and remove the position
// leaving it.
//
// An index is reachable only when it
// contains '0' and the current
// window has at least one reachable
// position.

// TC: O(N)
// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}