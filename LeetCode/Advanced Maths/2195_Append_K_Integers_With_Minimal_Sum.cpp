#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Optimal
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k){
        long long ans = 0;
        long long cur = 1;
        
        sort(nums.begin(), nums.end());

        for(int num : nums){
            if(num < cur) continue;

            long long cnt = min((long long)k, (long long)num - cur);

            ans += (cur + cur + cnt - 1) * cnt / 2;

            k -= cnt;

            if(k == 0) return ans;

            cur = (long long)num + 1;
        }

        ans += (cur + cur + k - 1) * 1LL * k / 2;

        return ans;
    };
};

// Technique:
// Sorting + Arithmetic Progression

// Approach:
// Sort the array and process numbers
// in increasing order.
// For each gap between consecutive
// existing numbers, take as many missing
// positive integers as possible.
// Compute their contribution using the
// arithmetic progression sum formula
// instead of enumerating them.
// If K numbers are still needed after
// processing all gaps, take them after
// the largest processed value.

// TC: O(N log N)
// N => Length of the array

// SC: O(1)
// Ignoring sorting space

// Verdict: Optimal



// Brute Force
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        long long sum = 0;

        for(int num : nums){
            sum += num;

            mpp[num] = 1;
        }

        long long num  = 0;
        long long kSum = 0;

        while(k){
            num++;
            if(mpp[num]) continue;
            sum  += num;
            kSum += num;
            k--;
        }

        return kSum;
    }
};

// Technique:
// Hashing + Simulation

// Approach:
// Store all existing numbers in a hash map
// for O(1) lookups.
// Starting from 1, keep selecting the
// smallest positive integers not present
// in the array.
// Add each selected number to the answer
// until exactly K numbers have been chosen.
// Return the accumulated sum.

// TC: O(N + X)
// N => Length of the array
// X => Largest number checked while selecting
//      K missing positive integers

// SC: O(N)
// N => Hash map storage

// Verdict: Brute

int main(){
    // Main Function placeholder for testing
    return 0;
}