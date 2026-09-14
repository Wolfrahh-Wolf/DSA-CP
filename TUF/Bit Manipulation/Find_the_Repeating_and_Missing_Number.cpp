#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums){
        int n = nums.size();
        int xr = 0;

        for(int i = 0; i < n; i++){
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        int number = (xr & ~(xr - 1));

        int zero = 0;
        int one = 0;

        for(int i = 0; i < n; i++){
            if((nums[i] & number) != 0) one ^= nums[i];
            else zero ^= nums[i];
        }

        for(int i = 1; i <= n; i++){
            if((i & number)) one ^= i;
                
            else zero ^= i;
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == zero) cnt++;
        }

        if(cnt == 2) return {zero, one};

        return {one, zero};
    }
};

// Technique:
// Bit Manipulation (XOR Partitioning)

// Approach (Normal):
// XOR all array elements and numbers
// from 1 to N.
// The result becomes:
//
// Missing ^ Repeating
//
// Find the rightmost set bit in this XOR.
// Use that bit to partition numbers into
// two groups and XOR each group separately.
// This isolates the missing and repeating
// numbers.
// Finally, determine which of the two
// candidates is repeating by counting
// its occurrences in the array.


// TC: O(N)
// N => Length of the array

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}