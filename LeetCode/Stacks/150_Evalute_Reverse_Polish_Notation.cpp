#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool isOperator(string str){
        if(str == "+" ||
           str == "-" ||
           str == "*" ||
           str == "/") return true;

        return false;
    }

public:
    int evalRPN(vector<string>& tokens){
        stack<int> st;

        for(string tok : tokens){
            if(isOperator(tok)){
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();

                if(tok == "+")      st.push(op1 + op2);
                else if(tok == "-") st.push(op1 - op2);
                else if(tok == "*") st.push(op1 * op2);
                else                st.push(op1 / op2);
            }

            else st.push(stoi(tok));
        }

        return st.top();
    }
};

// Technique:
// Stack

// Approach:
// Traverse the postfix expression token by token.
// Push operands into the stack.
// For every operator, pop the top two operands,
// perform the operation, and push the result back.
// Continue until all tokens are processed.
// The final stack element represents the answer.

// TC: O(N)
// N => Number of tokens
// Each token is processed once

// SC: O(N)
// N => Stack storage in worst case

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}