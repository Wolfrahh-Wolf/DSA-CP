#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution{	
public:	
    bool uniqueBinaryTree(int a, int b){
        return (a == 1 && b == 2 || a == 2 && b == 1) ||
               (a == 3 && b == 2 || a == 2 && b == 3);
    }
};

// Technique:
// Mathematical Observation

// Approach:
// A binary tree can be uniquely
// reconstructed only when one traversal
// is Inorder and the other is either
// Preorder or Postorder.
//
// Check whether the given pair satisfies
// this condition and return the result.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}