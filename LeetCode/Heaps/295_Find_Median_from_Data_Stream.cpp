#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MedianFinder{
private:
    priority_queue<int> maxx;
    priority_queue<int, vector<int>, greater<int>> minn;
public:
    MedianFinder(){
        
    }
    
    void addNum(int num){
        if(maxx.empty() || num <= maxx.top()) maxx.push(num);
        else minn.push(num);

        if(maxx.size() > minn.size() + 1){
            minn.push(maxx.top());
            maxx.pop();
        }
        else if(minn.size() > maxx.size()){
            maxx.push(minn.top());
            minn.pop();
        }
    }
    
    double findMedian(){
        if(minn.empty() && maxx.empty()) return 0.0;

        if(minn.size() == maxx.size()) return (minn.top() + maxx.top()) / 2.0;
        return (double)maxx.top();
    }
};

// Technique:
// Heaps
// Two Heaps (Max Heap & Min Heap)

// Approach:
// Maintain a max heap to store the
// smaller half of the numbers and a
// min heap to store the larger half.
//
// Insert the new number into the
// appropriate heap based on its
// value and rebalance the heaps so
// that their sizes differ by at
// most one.
//
// If both heaps have the same size,
// return the average of their top
// elements. Otherwise, return the
// top of the max heap.

// TC:
// addNum(): O(log N)
// findMedian(): O(1)

// SC: O(N)

// Verdict: Optimal

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    // Main Function placeholder for testing
    return 0;
}