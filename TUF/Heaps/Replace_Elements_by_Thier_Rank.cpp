#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceWithRank(vector<int>& arr){
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        sortedArr.erase(
            unique(sortedArr.begin(), sortedArr.end()),
            sortedArr.end()
        );
        
        // NOTE: unique -> Returns a iterator(it) at first duplicate by pushing the unique front
        // erase(): Deletes the Duplicates from it till end

        unordered_map<int, int> rank;

        for(int i = 0; i < sortedArr.size(); i++){
            rank[sortedArr[i]] = i + 1;
        }

        vector<int> result;
        for(int num : arr){
            result.push_back(rank[num]);
        }

        return result;
    }
};

// Technique:
// Sorting
// Coordinate Compression
// Hashing

// Approach:
// Create a sorted copy of the
// original array.
//
// Remove duplicate elements from
// the sorted array.
//
// Assign ranks to each unique
// element using a hash map.
//
// Traverse the original array and
// replace every element with its
// corresponding rank.

// TC: O(N log N) + O(N)

// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}