#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void insertAtBottom(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }

        int top = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(top);
        
    }
public:
    void reverseStack(stack<int> &st){
        if(st.empty()) return;

        int top = st.top();
        st.pop();

        reverseStack(st);
        
        insertAtBottom(st, top);
    }
};

// Technique:
// Recursion (Stack Manipulation)

// Approach:
// Use recursion to remove the top element until the stack becomes empty.
// While returning from recursion, insert each removed element
// at the bottom of the stack using a helper recursive function.
// This reverses the stack without using extra data structures.

// TC: O(N^2)
// N => Number of elements in the stack
// SC: O(N)
// N => Recursive Stack Depth

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}