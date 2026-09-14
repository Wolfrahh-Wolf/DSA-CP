#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st;
    int idx;

public:
    StockSpanner() {
        idx = 0;
    }

    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        int PGE;

        if(st.empty()) PGE = -1;
        else PGE = st.top().second;

        int span = idx - PGE;

        st.push({price, idx});

        idx++;

        return span;
    }
};

// Technique:
// Monotonic Stack
// Previous Greater Element

// Approach:
// Maintain a decreasing monotonic stack
// storing {Price, Index}.
//
// For every incoming price:
//
// Remove all prices smaller than or equal
// to the current price.
//
// The remaining stack top represents the
// Previous Greater Element.
//
// Compute:
//
// Span = Current Index - PGE Index
//
// Push the current price and index into
// the stack for future queries.

// TC: O(1) Amortized
// Each element is pushed and popped once

// SC: O(N)
// N => No of Prices Processed

// Verdict: Optimal

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){
    // Main Function placeholder for testing
    return 0;
}