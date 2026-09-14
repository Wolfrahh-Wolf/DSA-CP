#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        int n = nums.size();
        vector<int> ans;

        deque<int> dq;

        for(int i = 0; i < n; i++){
            if(!dq.empty() && dq.front() <= (i - k)) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            dq.push_back(i);

            if(i >= (k - 1)) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// Technique:
// Sliding Window + Monotonic Deque

// Approach:
// Maintain a deque storing indices of elements
// in decreasing order of their values.
// Remove indices that fall outside
// the current window.
// Remove smaller elements from the back
// since they can never become the maximum
// while the current larger element exists.
// Insert the current index into the deque.
// Once the first window is formed,
// the front of the deque always represents
// the maximum element of the current window.
// Store it in the answer array.
// Continue for all windows.

// TC: O(N)
// N => Length of the array
// Each index is pushed and popped at most once

// SC: O(K)
// K => Maximum deque size equals window size

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}