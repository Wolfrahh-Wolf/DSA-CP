#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
      
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
      
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }
    
    int countPairs(vector<int>& nums, int low, int mid, int high){
        int cnt = 0;

        int right = mid + 1;

        for(int i = low; i<=mid; i++){
            while(right <= high && nums[i] > 2LL * (long long)nums[right]) right++;
            
            // All Indices in this raneg satify the consition
            // (mid + 1) to (right - 1)
            cnt += (right - (mid+1));
        }

        return cnt;
    }

    int mS(vector<int>& nums, int low, int high){
        int cnt = 0;

        if(low >= high) return cnt; 
        
        int mid = (low + high) / 2;

        cnt += mS(nums, low, mid);
        cnt += mS(nums, mid + 1, high);

        // Recursive Counting
        cnt += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high); 

        return cnt;
    }

    int reversePairs(vector<int>& nums){
        int n = nums.size();  
        int cnt = 0;

        cnt += mS(nums, 0, n - 1);

        return cnt;
    }
};

// Technique:
// Merge Sort + Two Pointers

// Approach:
// Use Merge Sort to divide the array into two sorted halves.
// Before merging, count reverse pairs across the halves.
// For each element in the left half, find how many elements
// in the right half satisfy:
//
// nums[i] > 2 * nums[j]
//
// Since both halves are already sorted,
// a moving pointer can count valid pairs efficiently.
// After counting, merge both halves to maintain sorting.

// TC: O(N log N)
// N => Array size
// O(log N) => Merge Sort levels
// O(N) => Counting + Merging per level

// SC: O(N)
// N => Temporary array used during merge

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}