#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibility(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int bouquets =  0;
        int cnt = 0;
        
        for(int i = 0; i<n; i++){
            if(bloomDay[i] <= day){
                cnt++;
                if(cnt == k){
                    bouquets++;
                    cnt = 0;
                    if (bouquets >= m) return true;
                } 
            }
            else{
                cnt = 0;
            }
        }

        return false;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL * k * m;
        if(totalFlowers > bloomDay.size()) return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(possibility(bloomDay, mid, m, k)){
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return low;
    }
};

// Technique: Binary Search on Answer

// Approach:
// The minimum day lies between the earliest and latest bloom days.
// First, check the edge case where total required flowers (m * k)
// exceed the available flowers; if so, return -1.
// Use binary search on the number of days.
// For a chosen day, check feasibility by scanning the array and
// counting consecutive bloomed flowers.
// Every time k consecutive flowers are found, form one bouquet
// and reset the counter.
// If at least m bouquets can be formed, try to minimize the day
// by searching the left half; otherwise, search the right half.
// The final answer is the minimum feasible day.

// TC: O(N) x O(log D) = O(N log D)
// N => No of Flowers
// D => Highest Number of Days fora Flower to Bloom
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}