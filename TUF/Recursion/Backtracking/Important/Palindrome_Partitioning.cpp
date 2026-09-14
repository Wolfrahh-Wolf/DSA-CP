#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void func(int idx, string s, vector<string> subString, vector<vector<string>> &ans){
        if(idx == s.size()){
            ans.push_back(subString);
        }

        for(int i = idx; i < s.size(); ++i){
            if (isPalindrome(s, idx, i)){
                subString.push_back(s.substr(idx, i - idx + 1));
                func(i+1, s, subString, ans);
                subString.pop_back();
            }

        }
    }

    bool isPalindrome(string s, int start, int stop){
        while(start <= stop){
            if(s[start++] != s[stop--]) return false;
        }

        return true;
    }

public:
    vector<vector<string> > partition(string s) {
        vector<vector<string>> ans;
        vector<string> subString;
        
        func(0, s, subString, ans);

        return ans;
    }
};

// Technique: 
// Recursion
// Backtracking
// BFS - Breadth First Search

// Approach:
// Start partitioning the string from index 0.
// At each index, try all possible substrings ending at positions [idx … i].
// If the chosen substring is a palindrome, include it in the current partition
// and recursively process the remaining suffix starting from i + 1.
// Use backtracking to remove the last substring and explore other possibilities.
// When the index reaches the end of the string, a valid palindromic partition
// is formed and added to the answer.

// TC: O(N * 2^N)
// ==> O(N) => Sixe of the String(No of Elements)
// ==> O(2^N) => Number of Recursive Paths
// SC: O(N) => Recursive Stack + Current Partition Storage

// Verdict: Optimal


int main()
{
    // Main Function placeholder for testing
    return 0;
}