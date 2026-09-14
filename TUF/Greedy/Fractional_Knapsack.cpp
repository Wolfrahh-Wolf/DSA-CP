#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity){
        vector<pair<double, int>> ratio;

        for(int i = 0; i < val.size(); i++){
            double valDensity = (double)val[i] / wt[i];
            ratio.push_back({valDensity, i});
        }

        sort(ratio.rbegin(), ratio.rend());
        // Aliter 
        // sort(ratio.begin(), ratio.end(), greater<>());

        double value = 0;

        for(auto it : ratio){
            int i = it.second;

            if(capacity >= wt[i]){
                value += val[i];
                capacity -= wt[i];
            }
            else{
                value += (double)capacity * val[i] / wt[i];
                break;
            }
        }

        return round(value * 1e6) / 1e6;
    }
};

// Technique:
// Greedy
// Sorting

// Approach:
// Compute the value-to-weight ratio
// for every item and store it along
// with its index.
//
// Sort the items in descending
// order of their value density.
//
// Traverse the sorted items. Take
// the whole item if it fits within
// the remaining capacity.
// Otherwise, take the maximum
// possible fraction of the item and
// terminate the process.

// TC: O(N log N)
// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}