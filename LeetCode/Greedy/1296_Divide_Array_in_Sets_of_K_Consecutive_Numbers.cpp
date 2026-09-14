#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;

        map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        for(auto& [num, count] : freq){
            if(count > 0){
                for(int i = 1; i < k; i++){
                    if(freq[num + i] < count) return false;

                    freq[num + i] -= count;
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