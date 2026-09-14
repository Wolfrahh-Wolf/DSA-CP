#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCon = 0;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                maxCon = max(cnt, maxCon);
            }
            else cnt = 0;
        }
        return maxCon;
    }
};

// Approach: Have two variables, one to store maximum conscecutive 1s and one to store current consecutive 1s.
// Traverse once and find the Maximum No of Concecutive 1s.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}