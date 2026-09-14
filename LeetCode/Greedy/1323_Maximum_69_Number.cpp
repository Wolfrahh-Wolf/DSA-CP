#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '6'){
                s[i] = '9';
                return stoi(s);
            }
        }

        return num;
    }
};

// Technique:
// Greedy

// Approach:
// Convert the number into a string.
//
// Traverse the digits from left to
// right and change the first occurrence
// of '6' to '9'.
//
// Return the modified number.
//
// If no '6' exists, return the original
// number.

// TC: O(N)
// N => No of Digits

// SC: O(N)
// N => String Representation

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}