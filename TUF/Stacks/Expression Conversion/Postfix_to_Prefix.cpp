#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToPre(string s){
        stack<string> st;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            if(isalnum(c)) st.push(string(1, c));
            else{
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();

                string exp = c + op1 + op2;
                st.push(exp);
            }
        }

        return st.top();
    }
};

// Technique:
// Stack (Expression Conversion)

// Approach:
// Traverse the postfix expression from left to right.
// Push operands directly into the stack.
// For every operator, pop two operands,
// place the operator before both operands
// to form the prefix expression.
// Push the newly formed expression back into the stack.
// The final stack element gives the prefix expression.

// TC: O(N)
// N => Length of the expression
// Each character is processed once

// SC: O(N)
// N => Stack storage for intermediate expressions

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}