#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void insert(stack<int> &st, int val){
        if(st.empty() || st.top() <= val){
            st.push(val);
            return;
        }

        int temp = st.top();
        st.pop();
        
        insert(st, val);

        st.push(temp);
    }

public:
    void sortStack(stack<int> &st) {
        if(!st.empty()){
            int val = st.top();
            st.pop();

            sortStack(st);

            insert(st, val);
        }
    }
};

// Technique:
// Recursive Insertion Sort (Stack Sorting)

// Approach:
// Recursively extract all elements to bottom of stack (post-order).
// For each extracted element, use insert() to place it in correct sorted position.
// insert() recursively digs down until finding correct insertion point, then backtracks.
// Final stack is sorted with largest on top (stack order).

// TC: O(N^2) - Each insert takes O(N) average, N elements
// SC: O(N) - Recursion depth + temporary storage

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}