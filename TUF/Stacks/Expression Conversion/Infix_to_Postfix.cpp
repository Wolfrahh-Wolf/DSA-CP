#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int precedence(char op){
        if(op == '^') return 3;
        else if(op == '*' || op =='/') return 2;
        else if(op == '+' || op =='-') return 1;
    }

    bool isOperator(char op){
        return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
    }

    bool isLeftAssociative(char op){
        return op != '^';
    }

public:
    string infixToPostfix(string s){
        string ans = "";
        stack<char> st;

        for(char c : s){
            if(isalnum(c)) ans += c;
            
            else if(c == '(') st.push(c);

            else if(c == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }

            else if(isOperator(c)){
                while(!st.empty() && st.top() != '(' &&
                    (precedence(st.top()) > precedence(c) ||
                    (precedence(st.top()) ==  precedence(c) && isLeftAssociative(c)))){
                        ans += st.top();
                        st.pop();
                }
                st.push(c);
            }
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

// Technique:
// Stack (Operator Precedence Handling)

// Approach:
// Traverse the infix expression character by character.
// Append operands directly to the postfix string.
// Push '(' into the stack and process operators
// based on precedence and associativity.
// For ')', pop operators until '(' is encountered.
// For operators, pop higher precedence operators
// (or equal precedence for left-associative operators)
// before pushing the current operator.
// Finally, append remaining operators from the stack.

// TC: O(N)
// N => Length of the expression
// Each character is pushed and popped at most once

// SC: O(N)
// N => Stack storage in worst case

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}