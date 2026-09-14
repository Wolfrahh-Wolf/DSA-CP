#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Optimal - Best
class Solution{
public:
    int maxIceCream(vector<int>& costs, int coins){
        vector<int> freq(100001, 0);

        for(int cost : costs){
            freq[cost]++;
        }

        int cnt = 0;

        for(int cost = 1; cost <= 100000; cost++){
            if(coins < cost) return cnt;
            if(freq[cost] == 0) continue;

            int canBuy = min(freq[cost], coins / cost);

            cnt += canBuy;
            coins -= canBuy * cost;
        }

        return cnt;
    }
};

// Technique:
// Greedy
// Counting Sort

// Approach:
// Count the frequency of every ice cream
// cost using a frequency array.
//
// Traverse costs from the cheapest to
// the most expensive.
//
// For each cost, buy as many ice creams
// as possible without exceeding the
// available coins.
//
// Update the remaining coins and the
// total count purchased.
//
// Return the maximum number of ice
// creams that can be bought.

// TC: O(N + M)
// N => No of Ice Creams
// M => Maximum Cost Value (10^5)

// SC: O(M)
// M => Frequency Array Size

// Verdict: Optimal

// =======================================================

// Optimal - Better
class Solution{
public:
    int maxIceCream(vector<int>& costs, int coins){
        sort(costs.begin(), costs.end());

        int cnt = 0;

        for(int cost : costs){
            if(cost > coins) break;

            coins -= cost;
            cnt++;
        }

        return cnt;
    }
};

// Technique:
// Greedy
// Sorting

// Approach:
// Sort the ice cream costs in
// non-decreasing order.
//
// Always buy the cheapest available
// ice cream first to maximize the
// total number of ice creams bought.
//
// Continue purchasing until the
// remaining coins become insufficient
// to buy the next ice cream.
//
// Return the total count purchased.

// TC: O(N log N)
// N => No of Ice Creams

// SC: O(1)
// Ignoring Sorting Space

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}