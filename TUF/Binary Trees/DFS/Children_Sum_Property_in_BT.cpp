#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkChildrenSum(TreeNode* root){
        if(!root) return true;

        if(!root->left && !root->right) return true;

        int left  = root->left  ? root->left->val  : 0;
        int right = root->right ? root->right->val : 0;
        int sum   = left + right;

        if(root->val != sum) return false;

        return checkChildrenSum(root->left) &&
               checkChildrenSum(root->right);
    }
};

// Technique:
// Breadth First Search (BFS)
// Level Order Traversal

// Approach:
// Perform a level order traversal while
// assigning each node an index based on
// its position in the complete binary
// tree representation.
//
// Normalize the indices at every level
// by subtracting the leftmost index to
// prevent integer overflow.
//
// Compute the width of the current level
// as the difference between the first
// and last normalized indices plus one.
//
// Update the maximum width over all
// levels.

// TC: O(N)
// N => No of Nodes

// SC: O(N)
// N => Queue

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}