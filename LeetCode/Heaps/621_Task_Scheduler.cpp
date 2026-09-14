#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int leastInterval(vector<char>& tasks, int n){
        vector<int> freq(26, 0);

        for(char task : tasks){
            freq[task - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCnt  = count(freq.begin(), freq.end(), maxFreq);

        int partCnt = maxFreq - 1;
        int partLen = n + 1;

        int emptySlots = (partCnt * partLen) + maxCnt;
        int totalSlots = max((int)tasks.size(), emptySlots);

        return totalSlots;
    }
};

// Technique:
// Greedy
// Frequency Counting
// Mathematical Formula

// Approach:
// Count the frequency of each task.
//
// Find the maximum task frequency
// and the number of tasks having
// that frequency.
//
// Compute the minimum slots needed
// based on the task with the maximum
// frequency.
//
// Return the maximum of the total
// number of tasks and the computed
// minimum slots.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}