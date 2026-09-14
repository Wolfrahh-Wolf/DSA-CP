#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> findNGEE(vector<int> &nums){
        int n = nums.size();

        stack<int> st;
        vector<int> NGEE(n);

        for(int i = n - 1; i >= 0; i--){
            int elem = nums[i];

            while(!st.empty() && nums[st.top()] < elem) st.pop();

            NGEE[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }
        
        return NGEE;
    }

    vector<int> findPGE(vector<int> &nums){
        int n = nums.size();

        stack<int> st;
        vector<int> PGEE(n);

        for(int i = 0; i < n; i++){
            int elem = nums[i];
            
            while(!st.empty() && nums[st.top()] <= elem) st.pop();

            PGEE[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }
        
        return PGEE;
    }

    vector<int> findNSEE(vector<int> &nums){
        int n = nums.size();

        stack<int> st;
        vector<int> NSE(n);

        for(int i = n - 1; i >= 0; i--){
            int elem = nums[i];
            
            while(!st.empty() && nums[st.top()] > elem) st.pop();

            NSE[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }
        
        return NSE;
    }

    vector<int> findPSE(vector<int> &nums){
        int n = nums.size();

        stack<int> st;
        vector<int> PSE(n);

        for(int i = 0; i < n; i++){
            int elem = nums[i];
            
            while(!st.empty() && nums[st.top()] >= elem) st.pop();

            PSE[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }
        
        return PSE;
    }

    long long sumSubarrayMin(vector<int> &nums){
        int n = nums.size();
        vector<int> NSEE  = findNSEE(nums);
        vector<int> PSE = findPSE(nums);

        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left  = i - PSE[i];
            long long right = NSEE[i] - i;

            long long freq = 1LL * left * right;
            long long val = 1ll * freq * nums[i];

            sum += val;
        }

        return sum;
    }

    long long sumSubarrayMax(vector<int> &nums){
        int n = nums.size();
        vector<int> NGE  = findNGEE(nums);
        vector<int> PGEE = findPGE(nums);

        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left  = i - PGEE[i];
            long long right = NGE[i] - i;

            long long freq = 1LL * left * right;
            long long val = 1ll * freq * nums[i];

            sum += val;
        }

        return sum;
    }

public:
    long long subArrayRanges(vector<int> &nums) {
        return sumSubarrayMax(nums) - sumSubarrayMin(nums);
    }
};

// Technique:
// Monotonic Stack + Contribution Technique

// Approach:
// The range of a subarray is:
//
// Maximum Element - Minimum Element
//
// Instead of generating all subarrays,
// calculate the total contribution of each element
// as a maximum and as a minimum.
//
// For minimum contribution:
// Find the Previous Smaller Element (PSE)
// and Next Smaller or Equal Element (NSEE).
//
// For maximum contribution:
// Find the Previous Greater Element (PGE)
// and Next Greater or Equal Element (NGEE).
//
// For every element:
//
// Contribution = nums[i] × left × right
//
// left  => Number of choices on the left
// right => Number of choices on the right
//
// Sum all maximum contributions and
// all minimum contributions separately.
//
// Answer:
//
// Sum(Maximum Contributions)
// -
// Sum(Minimum Contributions)

// TC: O(N)
// N => Array size
// Each element is pushed and popped
// at most once in every monotonic stack traversal

// SC: O(N)
// N => NGE, PGE, NSE, PSE arrays
//      and stack storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}