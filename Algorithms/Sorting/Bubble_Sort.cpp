#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Bubble Sort interface function
    // Sorts the array in ascending order by repeatedly swapping adjacent elements
    void bubbleSort(vector<int>& arr) {
        int sortStatus; // Flag to track if any swapping happened in each pass
        int size = arr.size();
        
        for(int i = size-1; i >=0; i--){
            sortStatus = 0; // Reset swap flag for each pass
            for(int j = 0; j<=i-1; j++){
                // Swapping
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    // Mark that a swap occurred during this pass
                    sortStatus = 1; 
                }
            }
            // If no swaps in this pass, array is sorted, break early to optimize
            if(sortStatus == 0){
                break;
            }
        }
    }
};


// Time Complexity: Worst Csse O(N^2) || Best Case: O(N)
// Space Complexity: O(1)


// ===> Recursive
class Solution{
public: 
    void bubbleSortHelper(vector<int>& nums, int n){
        if(n == 1) return;

        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                swap(nums[i], nums[i + 1]);
            }
        }

        bubbleSortHelper(nums, n - 1);
    }

public:
    vector<int> bubbleSort(vector<int>& nums){
        bubbleSortHelper(nums, nums.size());
        
        return nums;
    }
};

int main() {
    // Main Function placeholder for testing
    return 0;
}