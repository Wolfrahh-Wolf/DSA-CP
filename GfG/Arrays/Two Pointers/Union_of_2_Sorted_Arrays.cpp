#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> unionArr;
        int sizeA = a.size();
        int sizeB = b.size();
        
        int i = 0;
        int j = 0;

        // Two-Pointer Traversal
        while(i < sizeA && j < sizeB){
            if(a[i] <= b[j]){
                //Condition to check Uniquity
                if(unionArr.size() == 0 || unionArr.back() != a[i]){
                    unionArr.push_back(a[i]);
                }
                i++;
            }
            else{
                if(unionArr.size() == 0 || unionArr.back() != b[j]){
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }
        
        // Traversal for the left out elemenst in the longest Array
        while(i < sizeA){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        
        while(j < sizeB){
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
        
        return unionArr;
    }
};

// Technique:
// Two-Pointer

// Approach: Use 2 pointers simultaneously to find the smallest element, make sure it is unique and add it in the UnionArray

// TC: O(N1 + N2)
// SC: O(N1 + N2)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}