#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights){
        string ans = "";

        for(string word : words){
            int wordWeight = 0;

            for(char ch : word){
                wordWeight += weights[ch - 'a'];
            }

            wordWeight %= 26;

            ans.push_back('a' + (26 - wordWeight - 1));
        }
        
        return ans;
    }
};

// Technique:
// Simulation

// Approach:
// Process each word independently.
// Compute the total weight of the word
// by summing the weights of its characters.
// Reduce the total weight modulo 26
// to map it into the lowercase alphabet range.
// Generate the corresponding character:
//
// 'a' + (26 - wordWeight - 1)
//
// Append the generated character
// to the answer string.
// Return the final mapped string.

// TC: O(T)
// T => Total number of characters across all words

// SC: O(W)
// W => Number of words (output string size)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}