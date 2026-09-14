#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{	
private:
    static bool comparator(pair <int, char> &pair1, pair <int, char> &pair2){
        if(pair1.first > pair2.first) return true;
        if(pair1.first < pair2.first) return false;

        return pair1.second < pair2.second;
    }

public:
    string frequencySort(string& s){
        string result = "";
        pair <int, char> charFrequency[256];

        for(int i = 0; i < 256; i++){
            charFrequency[i] = {0, i};
        }

        for(int i = 0; i < s.size(); i++){
            charFrequency[s[i]].first++;
        }

        sort(charFrequency, charFrequency + 256, comparator);

        for(int i = 0; i < 256; i++){
            if(charFrequency[i].first == 0) return result;
            result += string(charFrequency[i].first, charFrequency[i].second);
        }

        return result;
    }
};

// Technique:
// Hashing + Custom Sorting

// Approach:
// Count the frequency of every character
// using a fixed-size frequency array.
// Store each character along with its frequency
// in a pair array.
// Sort the array in descending order of frequency.
// If two characters have the same frequency,
// sort them lexicographically.
// Construct the answer by appending each
// character frequency times in sorted order.

// TC: O(N)
// N => Length of the string
// O(N) => Frequency counting
// O(256 log 256) => Sorting constant-size array

// SC: O(1)
// Fixed-size array of 256 characters

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}