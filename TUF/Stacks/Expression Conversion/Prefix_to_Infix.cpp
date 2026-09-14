#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string prefixToInfix(string s){
        stack<string> st;

        for(int i = s.size() - 1; i >= 0; i--){
            char c = s[i];

            if(isalnum(c)) st.push(string(1, c));
            else{
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                string exp = "(" + op1 + c + op2 + ")";
                st.push(exp);
            }
        }

        return st.top();
    }
};

// Technique:
// Stack (Expression Conversion)

// Approach:
// Traverse the prefix expression from right to left.
// Push operands directly into the stack.
// For every operator, pop two operands,
// place the operator between them,
// and form a fully parenthesized infix expression.
// Push the newly formed expression back into the stack.
// The final stack element gives the infix expression.

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