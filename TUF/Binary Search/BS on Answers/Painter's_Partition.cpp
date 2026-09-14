#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool canPaint(vector<int>& C, int A, long long maxLen){
        long long total = 0;
        int painters = 1;

        for(int len : C){
            if(total + len > maxLen){
                painters++;
                total = len;

                if(painters > A) return false;
            }
            else total += len;
        }

        return true;
    }

public:
    int paint(int A, int B, vector<int>& C){
        long long low = *max_element(C.begin(), C.end());
        long long high = accumulate(C.begin(), C.end(), 0LL);
        long long ans = high;

        const int MOD = 10000003;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(canPaint(C, A, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return (int)((ans * B) % MOD);
    }
};

// Technique:
// Binary Search on Answer

// Approach:
// The answer lies between:
// - The largest board length
// - The sum of all board lengths
//
// Use Binary Search on the maximum length
// assigned to a painter.
// For a given maximum length,
// greedily assign consecutive boards
// to painters.
// If more than A painters are required,
// the maximum length is too small.
// Otherwise, it is a valid answer.
// Find the minimum valid maximum length
// and multiply it by the time taken
// to paint one unit board length.

// TC: O(N × log(S))
// N => Number of boards
// S => Sum of all board lengths

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}