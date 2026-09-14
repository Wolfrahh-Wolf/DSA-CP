#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{	
public:		
    string largestOddNumber(string& s){
        int idx = s.size() - 1;
        int start = 0;
        int end;
        
        while(idx >= 0 && s[idx] % 2 == 0) idx--;
        end = idx;

        while(start <= end && s[start] == '0') start++;

        return s.substr(start, end - start + 1);
    }
};

// Technique:
// Greedy Traversal

// Approach:
// Traverse from the end of the string
// to find the rightmost odd digit.
// Any valid largest odd number must end
// at this position.
// Remove leading zeros from the resulting
// prefix and return the obtained substring.
// If no odd digit exists, return an empty string.

// TC: O(N)
// N => Length of the string

// SC: O(1)
// Ignoring the output string returned by substr()

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}