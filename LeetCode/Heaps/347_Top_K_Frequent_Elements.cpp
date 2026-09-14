#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> ans;

        for(int &num : nums) freq[num]++;

        for(auto &it : freq){
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k) minHeap.pop();
        }

        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};

// Technique:
// Hashing
// Min Heap (Priority Queue)

// Approach:
// Count the frequency of every
// number using a hash map.
//
// Maintain a min heap of size K,
// where each element stores
// {frequency, number}.
//
// For every unique number, insert
// its frequency and remove the
// smallest frequency whenever the
// heap size exceeds K.
//
// The remaining elements in the
// heap represent the K most
// frequent numbers.

// TC: O(N log K)

// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}