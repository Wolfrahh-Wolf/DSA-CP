#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{	
public:		
    vector<int> singleNumber(vector<int>& nums){
        int n = nums.size();
        long XOR = 0;

        for(int i = 0; i < n; i++){
            XOR ^= nums[i];
        }

        int rightmost = (XOR & (XOR - 1)) ^ XOR;

        int XOR1 = 0;
        int XOR2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] & rightmost) XOR1 ^= nums[i];
            else XOR2 ^= nums[i];
        }

        if(XOR1 < XOR2) return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};

// Technique:
// Bit Manipulation (XOR Partitioning)
// Bucketing

// Approach:
// XOR all elements to obtain XOR of the two
// unique numbers since duplicates cancel out.
// Extract the rightmost set bit from the XOR result
// to identify a differing bit between the two uniques.
// Partition elements into two groups based on this bit.
// XOR elements within each group separately.
// Duplicate numbers cancel out, leaving the two
// unique elements.
// Return the result in sorted order.

// Dry Run: (Finding Rightmost Set Bit)

// Assume:
// XOR => 6 => 0110

// XOR - 1
// 0110 - 1 => 0101

// XOR & (XOR - 1)

//   0110
// & 0101
// -------
//   0100
// -------

// Removes the rightmost set bit

// rightmost = XOR ^ (XOR & (XOR - 1))

//   0110
// ^ 0100
// -------
//   0010
// -------

// Result => 0010
// Hence, rightmost set bit is isolated.

// TC: O(2N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}