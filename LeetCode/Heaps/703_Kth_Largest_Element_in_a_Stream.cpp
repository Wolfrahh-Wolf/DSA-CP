#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class KthLargest{
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums){
        K = k;

        for(int num : nums){
            if(pq.size() < k) pq.push(num);
            else if(num > pq.top()){
                pq.pop();
                pq.push(num);
            }
        }
    }

    int add(int val){
        if(pq.size() < K){
            pq.push(val);

            return pq.top();
        }
            
        if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        
        return pq.top();
    }
};

// Technique:
// Design
// Min Heap (Priority Queue)

// Approach:
// Maintain a min heap containing
// only the K largest elements seen
// so far.
//
// During initialization, insert
// elements until the heap reaches
// size K. For every remaining
// element, replace the heap's top
// only if the current element is
// larger.
//
// While adding a new value, insert
// it directly if the heap has fewer
// than K elements. Otherwise,
// replace the smallest element in
// the heap only if the new value is
// larger.
//
// The top of the min heap always
// represents the Kth largest
// element.

// TC:
// Constructor: O(N log K)
// add(): O(log K)

// SC: O(K)

// Verdict: Optimal

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){
    // Main Function placeholder for testing
    return 0;
}