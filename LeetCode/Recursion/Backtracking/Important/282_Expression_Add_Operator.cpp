#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(string &num, long long target, int pos, long long currEval,
            long long last, string &expr, vector<string> &ans){

        int n = num.size();

        if(pos == n){
            if(currEval == target)
                ans.push_back(expr);

            return;
        }

        long long currNo = 0;
        int exprLen = expr.size();

        for(int end = pos; end < n; ++end){
            if(end > pos && num[pos] == '0') break;

            currNo = currNo * 10 + (num[end] - '0');

            string part = num.substr(pos, end - pos + 1);
            
            if(pos == 0){
                expr.append(part);
                backtrack(num, target, end + 1, currNo, currNo, expr, ans);
                expr.erase(exprLen);
            }
            else{
                expr.push_back('+');
                expr.append(part);
                backtrack(num, target, end + 1, currEval + currNo, currNo, expr, ans);
                expr.erase(exprLen);

                expr.push_back('-');
                expr.append(part);
                backtrack(num, target, end + 1, currEval - currNo, -currNo, expr, ans);
                expr.erase(exprLen);

                expr.push_back('*');
                expr.append(part);
                backtrack(num, target, end + 1, currEval - last + last * currNo, last * currNo, expr, ans);
                expr.erase(exprLen);

            }
        }
    }

public:
    vector<string> addOperators(string s, int target){
        vector<string> ans;

        if(s.empty()) return ans;

        string expr;
        
        backtrack(s, target, 0, 0LL, 0LL, expr, ans);
        
        return ans;
    }
};

// Technique:
// Backtracking + Expression Evaluation Optimization

// Approach:
// Generate all possible expressions by inserting '+', '-',
// and '*' between digits.
// Build numbers incrementally while avoiding leading zeros.
// Track current evaluated currEval and previous operand during recursion
// to handle multiplication precedence without re-evaluating the expression.
// When the full string is processed,
// store expressions whose currEval equals the target.

// TC: O(4^N)
// 4^N => Possible partitions and operator insertions
// N => Length of the string

// SC: O(N)
// N => Recursive stack + expression construction

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}