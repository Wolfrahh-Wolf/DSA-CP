#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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
    
    long long int countInversionPairs(vector<int>& nums, int low, int mid, int high){
        long long int cnt = 0;
        int right = mid + 1;

        for(int i = low; i <= mid; i++){
            while(right <= high && nums[i] > nums[right]) right++; // Using 64-Bit Space to aovid overflow
            cnt += (right - (mid+1));
        }

        return cnt;
    }

    long long int mS(vector<int>& nums, int low, int high){
        long long int cnt = 0;
        if(low >= high) return cnt;

        int mid = (low + high) / 2;

        cnt += mS(nums, low, mid);
        cnt += mS(nums, mid + 1, high);
        cnt += countInversionPairs(nums, low, mid, high);

        merge(nums, low, mid, high); 
        
        return cnt;
    }

public:
    long long int numberOfInversions(vector<int> nums){
        long long int cnt = 0;
        int n = nums.size();

        cnt += mS(nums, 0, n - 1);

        return cnt;
    }
};

// Technique:
// Merge Sort + Counting

// Approach:
// During the merge sort process,
// count inversion pairs before merging.
// Since both halves are already sorted,
// for each element in the left half,
// determine how many elements in the right half
// are smaller than it.
// Accumulate these counts and then merge
// the two sorted halves.
// Sum the inversion counts obtained from
// the left half, right half, and cross pairs.

// TC: O(N log N)
// N => Length of the array
// O(log N) levels of recursion
// O(N) work per level

// SC: O(N)
// N => Temporary array used during merging

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}