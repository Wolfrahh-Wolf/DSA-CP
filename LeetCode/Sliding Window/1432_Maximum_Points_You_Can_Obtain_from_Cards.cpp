#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        int score = INT_MIN;

        int l = 0;
        int r = cardScore.size() - 1;

        int sum = 0;

        while(l < k){
            sum += cardScore[l++];
        }
        l--; // NOTE

        score = sum;

        while(l >= 0){
            sum -= cardScore[l--];
            sum += cardScore[r--];

            score = max(score, sum);
        }

        return score;
    }
};

// Technique:
// Sliding Window

// Approach:
// Compute the sum of the first K cards
// taken from the left.
//
// This serves as the initial answer.
//
// Then, one by one, replace cards taken
// from the left with cards taken from
// the right.
//
// After every replacement, update the
// current sum and the maximum score.
//
// Return the maximum score obtained
// across all possible left-right
// combinations.

// TC: O(K)
// K => No of Cards to Pick

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}