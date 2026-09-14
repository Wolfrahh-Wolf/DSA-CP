#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";

        int idx = s.size() - 1;

        while(idx >= 0){
            int start;
            int end;

            // Removal of Trailing Spaces
            while(idx >= 0 && s[idx] == ' ') idx--;

            end = idx;

            // Edge Case: String full of spaces
            if(idx < 0) return result;

            // Finding the Starting Index of the Non Space Character.
            while(idx >= 0 && s[idx] != ' ') idx--;

            start = idx + 1;

            // Add Space after the word
            if(!result.empty()) result += ' ';   

            result += s.substr(start, end - start + 1);
            // substr() Syntax => substr(startingIndex, length);
        }

        return result;
    }
};

// Technique:
// Two Pointers from Right to Left

// Approach:
// Start from end of string, skip trailing spaces to find word end.
// Then move left until hitting space to find word start.
// Extract word using substr() and append to result with space separator.
// Continue until beginning of string.

// TC: O(N)
// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}