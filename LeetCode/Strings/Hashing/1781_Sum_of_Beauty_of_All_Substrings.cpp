#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;

        for(int i = 0; i < s.size(); i++){
            vector<int> freq(26, 0);

            for(int j = i; j < s.size(); j++){
                freq[s[j] - 'a'] += 1;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;

                for(int f : freq){
                    if(f > 0){
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }

                totalBeauty += maxFreq - minFreq;
            }
        }

        return totalBeauty;
    }
};

// Technique:
// Hashing

// Approach:
// Generate all possible substrings by fixing
// a starting index and extending the ending index.
// Maintain a frequency array for the current substring.
// For every extension, compute the maximum and minimum
// non-zero character frequencies.
// The beauty of the substring is:
//
// maxFreq - minFreq
//
// Add the beauty of each substring to the answer
// and return the total beauty sum.

// TC: O(N² × 26)
// N => Length of the string
// O(N²) => Enumerating all substrings
// O(26) => Finding max and min frequencies

// SC: O(26) = O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}