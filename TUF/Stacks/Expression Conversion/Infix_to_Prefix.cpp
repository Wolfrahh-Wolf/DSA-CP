#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private: 
    int precedence(char op){
        if(op == '^') return 3;
        else if(op == '*' || op =='/') return 2;
        else if(op == '+' || op =='-') return 1;
    }

    bool isOperator(char op){
        return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
    }

    void swapParenthesis(string& s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') s[i] = ')';
            else if(s[i] == ')') s[i] = '(';
        }
    }

    string infixToPostfix(string& s){
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
                // NOTE: Associativity changes since reversed
                while(!st.empty() && st.top() != '(' &&
                    (precedence(st.top()) > precedence(c))){ 
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

public:
    string infixToPrefix(const string& s){
        string ans = s;

        reverse(ans.begin(), ans.end());
        swapParenthesis(ans);

        ans = infixToPostfix(ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Technique:
// Stack (Expression Conversion + Operator Precedence Handling)

// Approach:
// Reverse the infix expression and swap '(' with ')'.
// Convert the modified expression into postfix notation
// using operator precedence rules.
// While converting, handle equal precedence carefully
// since associativity changes after reversal.
// Reverse the generated postfix expression
// to obtain the final prefix notation.

// Approach: (infixToPostfix)
// Traverse the expression character by character.
// Append operands directly to the postfix string.
// Push '(' into the stack.
// For ')', pop operators until '(' is encountered.
// For operators, pop higher precedence operators
// while maintaining valid order after reversal,
// then push the current operator.
// Finally, append remaining operators from the stack.

// TC: O(N)
// N => Length of the expression
// Each character is processed a constant number of times

// SC: O(N)
// N => Stack storage + output string

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}