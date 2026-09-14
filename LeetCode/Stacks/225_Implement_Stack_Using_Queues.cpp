#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;
public:
    MyStack() {
        // Contructor
        // Left Empty as queue<int> q; will be initiated automatically 
        // upon calling this empty contructor.
    }

    void push(int x) {
        int s = q.size();

        q.push(x);

        for(int i = 0; i<s; i++){
            q.push(q.front());
            q.pop();        
        }
    }
    
    int pop() {
        int n = q.front();
        
        q.pop();
        
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

// Technique:
// Simulation (Queue to Implement Stack)

// Approach:
// Use a single queue to simulate stack (LIFO) behavior.
// On push, insert the element and rotate the previous elements
// behind it so that the newest element comes to the front.
// This ensures that pop and top operations can be performed
// directly from the front of the queue.

// TC:
// push  -> O(N)
// pop   -> O(1)
// top   -> O(1)
// empty -> O(1)
// N => Number of elements in the stack

// SC: O(N)
// N => Storage for queue

// Verdict: Optimal

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    // Main Function placeholder for testing
    return 0;
}