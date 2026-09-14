#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr){
        int n = arr.size();

        vector<int> ans(n, -1);

        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() >= arr[i]) st.pop();

            if(!st.empty()) ans[i] = st.top();

            st.push(arr[i]);
        }

        return ans;
    }
};

// Technique:
// Monotonic Stack (Increasing Stack)

// Approach:
// Traverse the array from right to left.
// Maintain a monotonic increasing stack
// containing potential next smaller elements.
// Remove all elements greater than or equal
// to the current element since they cannot
// serve as the next smaller element.
// If the stack is not empty,
// the top element is the next smaller element.
// Push the current element into the stack
// and continue for all indices.

// TC: O(N)
// N => Array size
// Each element is pushed and popped at most once

// SC: O(N)
// N => Stack storage in the worst case

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}