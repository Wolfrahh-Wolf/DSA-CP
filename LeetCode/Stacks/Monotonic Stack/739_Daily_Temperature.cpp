#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        int n = temperatures.size();

        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int prev = st.top();
                st.pop();

                ans[prev] = i - prev;
            }

            st.push(i);
        }

        return ans;      
    }
};

// Technique:
// Monotonic Stack
// Next Greater Element

// Approach:
// Traverse the temperatures from left to right.
//
// Maintain a stack of indices whose next warmer
// day has not been found yet.
//
// When the current temperature is greater than
// the temperature at the stack's top index,
// pop that index and store the difference
// between the current and previous indices.
//
// Remaining indices have no warmer future day,
// so their answers remain 0.

// TC: O(N)

// O(N) => Each index is pushed and popped at most once

// SC: O(N)

// O(N) => Answer Array
// O(N) => Monotonic Stack

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}