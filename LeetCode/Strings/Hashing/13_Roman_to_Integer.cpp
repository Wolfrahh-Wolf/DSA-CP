#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> roman = {{'M', 1000},
                                           {'D', 500},
                                           {'C', 100},
                                           {'L', 50},
                                           {'X' , 10},
                                           {'V', 5},
                                           {'I', 1}};

        int n = s.size();
        int intVal = 0;
        int i = 0;

        for(int i = 0; i < n-1; i++){
            if(roman[s[i]] < roman[s[i+1]]){
                intVal -= roman[s[i]];
            }
            else intVal += roman[s[i]];
        }

        intVal += roman[s[n-1]];

        return intVal;
    }
};

// Technique:
// Hashing + Greedy

// Approach:
// Traverse the Roman numeral from left to right.
// If the current symbol has a smaller value than
// the next symbol, subtract its value since it
// forms a subtractive pair.
// Otherwise, add its value to the answer.
// Finally, add the value of the last symbol
// and return the computed integer.

// TC: O(N)
// N => Length of the Roman numeral string

// SC: O(1)
// Fixed-size Roman numeral mapping

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}