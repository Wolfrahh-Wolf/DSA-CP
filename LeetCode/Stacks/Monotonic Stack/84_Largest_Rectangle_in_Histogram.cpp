#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int largestRectangleArea(vector<int> &heights){
        int maxArea = 0;
        int area;
        int PSE;
        int NSE;

        int n = heights.size();

        stack<int> st;

        for(int i = 0 ; i < n; i++){
            int elem = heights[i];

            while(!st.empty() && heights[st.top()] >= elem){
                int idx = st.top(); st.pop();

                PSE = st.empty() ? -1 : st.top();
                NSE = i;

                area = heights[idx] * (NSE - PSE - 1);

                maxArea = max(maxArea, area);
            }

            st.push(i);

        }

        while(!st.empty()){
            int idx = st.top(); st.pop();

            PSE = st.empty() ? -1 : st.top();
            NSE = n;

            area = heights[idx] * (NSE - PSE - 1);

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// Technique:
// Monotonic Stack

// Approach:
// Maintain a monotonic increasing stack
// storing indices of histogram bars.
// Whenever a smaller bar is encountered,
// the current bar becomes the Next Smaller Element (NSE)
// for bars in the stack.
// Pop those bars one by one and compute
// the maximum rectangle area where the popped bar
// acts as the minimum height.
//
// Width:
//
// NSE - PSE - 1
//
// PSE => Previous Smaller Element index
// NSE => Next Smaller Element index
//
// After traversing the array,
// process the remaining bars in the stack
// by assuming NSE = n.
// Return the maximum rectangle area found.

// TC: O(N)
// N => Number of histogram bars
// Each index is pushed and popped at most once

// SC: O(N)
// N => Stack storage in the worst case

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}