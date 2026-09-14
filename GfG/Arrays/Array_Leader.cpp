#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int maxElem = INT_MIN;
        int n = arr.size();
        
        for(int i = n-1; i>=0; i--){
            if(arr[i] >= maxElem){
                ans.push_back(arr[i]);
            }
            maxElem = max(arr[i], maxElem);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Approach
// Starting from the end, update maxElem when a larger element is found and add it to the result list.
// Any element greater than or equal to maxElem is a leader.
// Finally, reverse the result to maintain the original order.

// TC: O(N) => For Solving + O(N log N) => for Reversing
// SC: O(N)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}