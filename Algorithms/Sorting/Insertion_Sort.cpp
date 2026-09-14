#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Insertion Sort Function
    void insertionSort(vector<int>& arr) {
        
        int size = arr.size();
        
        // Traversal
        for(int i = 1; i<size; i++){
            int key = arr[i];
            int j = i-1;
            
            // Swapping it backward until it is in correct position
            while(j>0 && arr[j-1] > key){
                arr[j+1] = arr[j];
                j--;
            }

            arr[j-1] = key;
        }
    } 
};

// Time Complexity: O(N^2)
// Space Complexity: O(1)


// ===> Recursive
class Solution{
private:
    void insertionSortHelper(vector<int>& nums, int n){
        if(n <= 1) return;

        insertionSortHelper(nums, n - 1);

        int last = nums[n - 1];
        int j = n - 2;

        while(j >= 0 && nums[j] > last){
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = last;
    }

public:
    vector<int> insertionSort(vector<int>& nums){
        insertionSortHelper(nums, nums.size());

        return nums;
    }
};

int main() {
    // Main Function placeholder for testing
    return 0;
}