#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = prices[0];
        int maxProfit = 0;
        int profit = 0;

        for(int i = 0; i<prices.size(); i++){
            profit = prices[i] - cost;
            maxProfit = max(profit, maxProfit);
            cost = min(prices[i], cost);
        }

        return maxProfit;
    }
};

// Technique:
// Greedy

// Approach:
// Keep track of the minimum stock price seen so far.
// For each day, calculate the profit if sold on that day and update the maximum profit accordingly.
// For each day, upadte the codt to the minimum price seen so far.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}