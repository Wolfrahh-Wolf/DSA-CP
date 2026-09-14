#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string removeDuplicateLetters(string s){
        vector<int> lastIdx(26);
        vector<bool> visited(26, false);

        for(int i = 0; i < s.size(); i++){
            lastIdx[s[i] - 'a'] = i;
        }

        string ans;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            if(visited[ch - 'a']) continue;

            while(!ans.empty() &&
                  ans.back() > ch && lastIdx[ans.back() - 'a'] > i){
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return ans;
    }
};

// Technique:
// Greedy
// Monotonic Stack

// Approach:
// Store the last occurrence index
// of every character.
//
// Traverse the string.
//
// Skip the current character if it
// is already included in the answer.
//
// While the current character is
// smaller than the last character
// in the answer and the last
// character appears again later,
// remove it from the answer.
//
// Add the current character to the
// answer and mark it as visited.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}