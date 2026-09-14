#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks){
        int totalCost = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int &stick : sticks){
            pq.push(stick);
        }

        while(pq.size() > 1){
            int stick1 = pq.top();
            pq.pop();

            int stick2 = pq.top();
            pq.pop();

            int cost = stick1 + stick2;

            totalCost += cost;

            pq.push(cost);
        }

        return totalCost;
    }
};

// Technique:
// Greedy
// Min Heap (Priority Queue)

// Approach:
// Insert all stick lengths into a
// min heap.
//
// Repeatedly remove the two
// smallest sticks, connect them,
// and add the connection cost to
// the total cost.
//
// Push the newly formed stick back
// into the min heap.
//
// Continue until only one stick
// remains.

// TC: O(N log N)

// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}