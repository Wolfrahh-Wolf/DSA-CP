#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices){
        vector<int> ans;

        for(int idx : indices){
            int cnt = 0;

            for(int i = idx + 1; i < arr.size(); i++){
                if(arr[i] > arr[idx]) cnt++;
            }

            ans.push_back(cnt);        
        }

        return ans;
    }
};

// Technique:
// Brute Force

// Approach:
// For each queried index,
// traverse all elements to its right.
// Count the elements that are greater
// than the value at the queried index.
// Store the count for every query
// and return the final result.

// TC: O(Q × N)
// Q => Number of queried indices
// N => Length of the array

// SC: O(1)

// Verdict: Brute Force

int main(){
    // Main Function placeholder for testing
    return 0;
}