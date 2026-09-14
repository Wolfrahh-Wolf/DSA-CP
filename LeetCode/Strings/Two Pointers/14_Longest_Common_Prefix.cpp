#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if (str.empty()) return "";

        sort(str.begin(), str.end());

        string first = str[0];
        string last = str[str.size() - 1];

        string ans = "";

        int minLength = min(first.size(), last.size());

        for (int i = 0; i < minLength; i++) {
            if (first[i] != last[i]) break;

            ans += first[i];
        }

        return ans;
    }
};

// Technique:
// Sorting
// Pointer Traversal

// Approach:
// Sort the input array of strings so that the strings with the smallest and largest lexicographical orders become first and last.
// The longest common prefix of the whole array must be a prefix of these two strings.
// Compare characters of the first and last string one by one until a mismatch or the end of either string is reached.
// Accumulate matched characters as the longest common prefix.

// TC: O(N * log N + M) 
// O(N * log N) => Sorting
// O(M) => Comparison of Characters
// SC: O(M)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}