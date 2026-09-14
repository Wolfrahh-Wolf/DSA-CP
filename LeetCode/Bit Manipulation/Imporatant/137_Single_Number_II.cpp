#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones;
    }
};

// Technique:
// Bit Manipulation (Bit Bucket)

// Approach:
// Track bits appearing once and twice
// using two bitmasks: ones and twos.
// When a bit appears:
// 1st time -> stored in ones => Store in ones if not in twos
// 2nd time -> moved to twos  => Store in twos if not in ones
// 3rd time -> removed from both
// After processing all elements,
// ones contains the element appearing once.

// Dry Run:
// nums => [0, 1, 0, 1, 0, 1, 99]

// 0  => 0000
// 1  => 0001
// 99 => 1100011

// Initially:
// ones => 0000000
// twos => 0000000

// num = 0

// ones = (0000000 ^ 0000000) & ~0000000
//      = 0000000

// twos = (0000000 ^ 0000000) & ~0000000
//      = 0000000

// num = 1

// ones = (0000000 ^ 0000001) & ~0000000
//      = 0000001

// twos = (0000000 ^ 0000001) & ~0000001
//      = 0000000

// num = 0

// ones = (0000001 ^ 0000000) & ~0000000
//      = 0000001

// twos = (0000000 ^ 0000000) & ~0000001
//      = 0000000

// num = 1

// ones = (0000001 ^ 0000001) & ~0000000
//      = 0000000

// twos = (0000000 ^ 0000001) & ~0000000
//      = 0000001

// num = 0

// ones = (0000000 ^ 0000000) & ~0000001
//      = 0000000

// twos = (0000001 ^ 0000000) & ~0000000
//      = 0000001

// num = 1

// ones = (0000000 ^ 0000001) & ~0000001
//      = 0000000

// twos = (0000001 ^ 0000001) & ~0000000
//      = 0000000

// (Bit '1' appeared 3 times -> removed from both)

// num = 99

// ones = (0000000 ^ 1100011) & ~0000000
//      = 1100011

// twos = (0000000 ^ 1100011) & ~1100011
//      = 0000000

// Final:
// ones => 1100011 => 99
// Hence, unique element = 99

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}