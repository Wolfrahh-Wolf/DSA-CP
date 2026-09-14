#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxTurbulenceSize(vector<int>& arr){
        int n = arr.size();

        int len = 1;
        int maxi = 1;

        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i - 1]){
                if(i > 1 && arr[i - 1] < arr[i - 2])
                    len++;
                else len = 2;
            }
            else if(arr[i] < arr[i - 1]){
                if(i > 1 && arr[i - 1] > arr[i - 2])
                    len++;
                else len = 2;
            }
            else len = 1;

            maxi = max(maxi, len);
        }

        return maxi;
    }
};

// Technique:
// Greedy
// Dynamic Programming

// Approach:
// Maintain the length of the
// current turbulent subarray.
//
// If the current comparison is
// opposite to the previous
// comparison, extend the current
// length.
//
// If the alternating pattern breaks,
// restart the length from 2.
//
// If two adjacent elements are
// equal, reset the length to 1.
//
// Track the maximum turbulent
// subarray length throughout the
// traversal.

// TC: O(N)

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}