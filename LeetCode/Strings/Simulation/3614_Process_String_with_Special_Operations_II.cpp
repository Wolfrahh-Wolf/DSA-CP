#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        for(char ch : s){
            if(ch == '*'){
                if(len > 0) len--;
            }
            else if(ch == '#') len *= 2;
            else if(ch != '%') len++;
        }

        if(k >= len) return '.';

        for(int i = s.size() - 1; i >= 0; i--){
            char ch = s[i];

            if(ch == '*') len++;
            else if(ch == '#'){
                len /= 2;

                if(k >= len) k -= len;
            }
            else if(ch == '%') k = len - 1 - k; // NOTE
            else{
                len--;

                if(k == len) return ch;
            }
        }

        return '.';
    }
};

// Technique:
// Reverse Simulation

// Approach:
// First, compute the final length of the
// processed string without actually
// constructing it.
// Starting from the end of the operations,
// trace the required index k back through
// each operation:
//
// '#' : Map k to the corresponding position
//       in the original half.
//
// '%' : Map k to its position before reversal.
//
// Character : Check whether the current
//             character generated index k.
//
// Continue reversing the operations until
// the originating character is found.

// TC: O(N)
// N => Length of the input string

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}