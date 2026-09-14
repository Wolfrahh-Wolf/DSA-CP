#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long divisionSum(vector<int>& nums, int divisor){
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i<n; i++){
            // Using Double to get the Floating Points to correct ceil value
            // sum += ceil((double)nums[i] / (double)divisor);

            // Integer Arithmetic Alternative
            sum += (nums[i] + divisor - 1) / divisor;
        }

        return sum;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid =  low + (high - low) / 2;

            long long sum = divisionSum(nums, mid);

            if(sum <= threshold){
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return low;
    }
};

// Technique:
// BS - Binary Search on Answer

// Approach:
// The divisor lies in the range [1, max(nums)].
// Use binary search to find the smallest divisor such that the
// sum of ceil(nums[i] / divisor) over all elements is ≤ threshold.
// For a given divisor, compute the division sum using integer
// arithmetic to avoid floating point precision issues.
// If the sum is within the threshold, try to minimize the divisor
// by searching the left half; otherwise, increase the divisor.
// The final answer is the minimum valid divisor.

// TC: O(N log M)
// N => No of Elements
// M => Max Element
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}