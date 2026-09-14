#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr){
        map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];

            if(sum == 0) maxLen = max(maxLen, i+1);
            
            long long rem = sum;

            if(preSumMap.find(rem) != preSumMap.end()){
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            if(preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};

// Technique:
// Prefix Sum 
// Hash Map

// Approach:
// Use a running prefix sum and store the earliest index where each prefix sum occurs in a map.
// For each prefix sum, check if (prefixSum - k) has appeared before.
// Update max length based on the distance between current index and stored index for (prefixSum - k).

// TC: O(N)
// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}