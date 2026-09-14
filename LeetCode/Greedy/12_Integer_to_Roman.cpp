#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> mpp = {
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1}
        };

        string ans = "";

        int n = mpp.size();

        for(int i = 0; i < n; i++){
            while(num >= mpp[i].second){
                num -= mpp[i].second;
                ans += mpp[i].first;
            }
        }

        return ans;
    }
};

// Technique:
// Greedy

// Approach:
// Store all Roman numeral symbols along
// with their corresponding values in
// descending order.
//
// Traverse the list and repeatedly use
// the largest possible symbol while its
// value does not exceed the remaining
// number.
//
// Append the selected symbol to the
// answer and reduce the number.
//
// Continue until the number becomes zero.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}