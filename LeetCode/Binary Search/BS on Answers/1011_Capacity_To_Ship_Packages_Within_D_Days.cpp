#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int CountNoOfDays(vector<int>& weights, int capacity, int days, int n){
        int noOfDays = 1;
        long long sum = 0;
        
        for(int i = 0; i<n; i++){
            sum += weights[i];

            if(sum > capacity){
                noOfDays += 1;
                if(noOfDays > days) return noOfDays;
                sum = weights[i];
            }
        }

        return noOfDays;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <=  high){
            int mid = low + (high - low) / 2;

            int noOfDays = CountNoOfDays(weights, mid, days, n);

            if(noOfDays <= days)  high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};

// Technique:
// BS – Binary Search on Answer

// Approach:
// Search for the minimum ship capacity in the range
// [max(weights), sum(weights)].
// For a given capacity, simulate shipping to check
// if all packages can be shipped within the given days.
// Use binary search to minimize the valid capacity.

// TC: O(N log M)
// N => Number of Packages 
// M => Search Space for Capacity = sum(weights) − max(weights)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}