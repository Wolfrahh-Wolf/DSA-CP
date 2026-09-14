#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isNStraightHand(vector<int>& hand, int groupSize){
        if(hand.size() % groupSize != 0) return false;

        map<int, int> freq;

        for(int card : hand){
            freq[card]++;
        }

        for(auto& [card, count] : freq){
            if(count > 0){
                for(int i = 1; i < groupSize; i++){
                    if(freq[card + i] < count) return false;

                    freq[card + i] -= count;
                }
            }
        }

        return true;
    }
};

// Technique:
// Greedy
// Hashing
// Ordered Map

// Approach:
// Count the frequency of every card
// using an ordered map.
//
// Traverse the cards in ascending
// order.
//
// For each card with a positive
// frequency, start that many groups.
//
// Check whether the next consecutive
// cards have sufficient frequency to
// complete all the groups.
//
// Reduce the frequencies of the
// consecutive cards accordingly.

// TC: O(N log N)

// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}