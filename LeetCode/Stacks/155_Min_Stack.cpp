#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
class MinStack {
private:
    stack<long long> st;
    long long  mini;

public:
    MinStack() {
   
    }

// Intuition: 
// The mini should always be the mini, if not do the Encoding or Decoding.
// encoded < current minimum

    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else{
            if(mini < value) st.push(value);
            else{
                st.push(2LL * value - mini); // NOTE
                mini = value;
            }
        }
    }

    void pop() {
        if(st.empty()) return;

        long long top = st.top();
        st.pop();

        if(top < mini) // NOTE
            mini = 2LL * mini - top;
    }

    long long top() {
        if(st.empty()) return -1;

        long long top = st.top();

        if(mini < top) return top; // NOTE

        return mini;

    }

    long long getMin() {
        return mini;
    }
};

// Technique:
// Stack (Min Stack with Encoding)

// Intuition: 
// The mini should always be the mini, if not do the Encoding or Decoding.
// encoded < current minimum

// Formula:
// Push (Encoding): if newVal < mini
// encodedValue = 2 * newMini - oldMin
// encodedValue = 2 * newVal - mini

// Pop (Decoding): if (top < mini)
// previousMin = 2 * currentMin - encodedValue
// decodedVal  = 2 * mini - top

// Approach:
// Store minimum element separately while using a single stack.
// If a new value becomes the new minimum,
// push an encoded value instead of the actual value.
// During pop, decode the previous minimum when an encoded
// value is encountered.
// This allows retrieving the minimum element in O(1)
// without using extra space for another stack.

// TC:
// push   -> O(1)
// pop    -> O(1)
// top    -> O(1)
// getMin -> O(1)

// SC: O(N)

// Verdict: Optimal



int main(){
    // Main Function placeholder for testing
    return 0;
}