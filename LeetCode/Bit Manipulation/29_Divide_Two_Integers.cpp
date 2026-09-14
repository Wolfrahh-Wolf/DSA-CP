#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor){
        if(dividend == divisor) return 1;
        if(divisor == 1) return dividend;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool isPositive = true;

        if(dividend <= 0 && divisor > 0 || divisor < 0 && dividend >= 0)
            isPositive = false;

        long long n = abs(dividend);
        long long d = abs(divisor);

        int ans = 0;

        while(n >= d){
            int cnt = 0;

            while(n >= (d << (cnt + 1))) cnt++;

            ans += (1 << cnt);
            n -= (d << cnt);
        }

        if(ans == (1 << 31) && isPositive)  return INT_MAX;
        if(ans == (1 << 31) && !isPositive) return INT_MIN;

        return isPositive ? ans : -1 * ans;
    }
};

// Technique:
// Bit Manipulation + Greedy

// Approach:
// Convert dividend and divisor to positive values.
// Repeatedly find the largest power of 2 multiple
// of divisor that can be subtracted from dividend.
// Use left shift to efficiently multiply divisor
// by powers of 2.
// Add the corresponding quotient contribution
// and reduce the remaining dividend.
// Restore the sign at the end and handle overflow cases.

// Dry Run:
// dividend => 29
// divisor  => 3

// Find largest multiple:
// 3 << 3 => 24 <= 29
// 3 << 4 => 48 > 29

// quotient += (1 << 3)
// quotient += 8

// remaining:
// 29 - 24 = 5

// Again:
// 3 << 0 => 3 <= 5
// quotient += (1 << 0)
// quotient += 1

// remaining:
// 5 - 3 = 2

// Final Quotient:
// 8 + 1 = 9

// TC: O((log N) × (log N)) = O(log² N)
// O(log N) => Outer subtraction loop
// O(log N) => Inner loop to find largest valid shift

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}