#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long calcTotalHrs(vector<int>& piles, int speed){
        long long sum = 0;

        for(int i = 0; i < piles.size(); i++){
           sum += (piles[i] + speed - 1) / speed;
        }

        return sum;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h){
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long totalHrs = calcTotalHrs(piles, mid);

            if(totalHrs <= h) high = mid - 1;
            else low = mid +  1;
        }

        return low;
    }
};

// Technique:
// BS - Binary Search on Answer

// Approach:
// The eating speed lies between 1 and the maximum pile size.
// Use binary search to find the minimum speed at which all bananas
// can be eaten within h hours.
// For a chosen speed, compute the total hours required by summing
// ceil(piles[i] / speed) for all piles.
// If the total hours are within h, try to minimize the speed by
// moving the search space to the left.
// Otherwise, increase the speed.
// The final answer is the lowest valid speed.

// TC: O(N) × O(log M) = O(N log M)
// O(N)     => Finding Total Hours
// O(log M) => BS
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}