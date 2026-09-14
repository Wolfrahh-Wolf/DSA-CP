#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxNumberOfBalloons(string text){
        vector<int> freq(26, 0);
    
        for(char ch : text) freq[ch - 'a']++;

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};

// Technique:
// Frequency Counting

// Approach:
// Count the frequency of every character
// in the given string.
//
// The word "balloon" requires:
//
// b -> 1
// a -> 1
// l -> 2
// o -> 2
// n -> 1
//
// Compute the maximum number of times
// each required character can contribute
// towards forming "balloon".
//
// Since 'l' and 'o' are needed twice,
// divide their frequencies by 2.
//
// The minimum among all required
// character counts gives the maximum
// number of balloons that can be formed.

// TC: O(N)
// N => Length of the String

// SC: O(1)
// Frequency Array of Size 26

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}