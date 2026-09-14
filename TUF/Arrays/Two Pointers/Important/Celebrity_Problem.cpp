#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();

        int top = 0;
        int down = n - 1;

        while(top < down){
            if(M[top][down] == 1) top++;
            else if(M[down][top] == 1) down--;
            else{
                top++;
                down--;
            }
        }

        if(top > down) return -1;

        for(int i = 0; i < n; i++){
            if(i == top) continue;

            if(M[top][i] == 1 || M[i][top] == 0){
                return -1;
            }
        }

        return top;
    }
};

// Technique:
// Two Pointers

// Approach:
// Maintain two pointers:
//
// top  -> First Person
// down -> Last Person
//
// Compare the relationship between
// the two candidates and eliminate
// at least one non-celebrity in every step.
//
// After the elimination process,
// only one potential celebrity remains.
//
// Verify the candidate by checking:
//
// - Celebrity knows nobody.
// - Everybody knows the celebrity.
//
// Return the candidate if valid,
// otherwise return -1.

// TC: O(N)
// N => No of People
//
// O(N) for elimination +
// O(N) for verification

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}