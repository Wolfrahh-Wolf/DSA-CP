#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int noOfStudents(vector<int> &nums, int pages, int m){
        int studentCnt = 1;
        long long total = 0;
        
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            if(total > pages){
                studentCnt += 1;
                if(studentCnt > m) return studentCnt;
                total = nums[i];
            }
        }
        
        return studentCnt;
    }

public:
    int findPages(vector<int> &nums, int m) {
        
        if(m > nums.size()) return -1;
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int studentCnt = noOfStudents(nums, mid, m);
            
            if(studentCnt > m) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
};

// Technique:
// BS – Binary Search on Answer

// Approach:
// Search for the minimum possible maximum pages allocation
// in the range [max(nums), sum(nums)].
// For a given page limit, greedily allocate books to students
// and count how many students are required.
// Use binary search to minimize the page limit while ensuring
// the number of students does not exceed m.

// TC: O(N) x O(log M) = O(N log M)
// N => Number of books
// M => Search space for pages = sum(nums) − max(nums)
// SC: O(1)

// Verdict: Optimal


int main()
{
    // Main Function placeholder for testing
    return 0;
}