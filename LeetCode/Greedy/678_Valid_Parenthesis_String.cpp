#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{  
public:
    bool checkValidString(string s){
        int minOpen  = 0;
        int maxOpen  = 0;

        for(char ch : s){
            if(ch == '('){
                minOpen++;
                maxOpen++;
            }
            else if(ch == ')'){
                minOpen--;
                maxOpen--;
            }
            else{
                // NOTE
                minOpen--; // * => )
                maxOpen++; // * => (
            }
            
            if(maxOpen < 0) return false;
            if(minOpen < 0) minOpen = 0; // Min should never go below Zero
        }

        return minOpen == 0;
    }
};

// Technique:
// Greedy

// Approach:
// Maintain the minimum and maximum
// possible number of unmatched
// opening brackets.
//
// For '(' increase both counts.
//
// For ')' decrease both counts.
//
// For '*', treat it as ')' while
// updating the minimum count and
// as '(' while updating the
// maximum count.
//
// If the maximum count becomes
// negative, the string is invalid.
//
// The minimum count should never
// become negative.
//
// The string is valid only if the
// minimum possible unmatched
// opening brackets is zero at the
// end.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}