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

class Solution{
private:
    bool isValid_BST(TreeNode* root, long min, long max){
        if(!root) return true;

        if(root->val <= min || root->val >= max) return false;

        return isValid_BST(root->left,  min, root->val) &&
               isValid_BST(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root){
        return isValid_BST(root, LONG_MIN, LONG_MAX);
    }
};

// Technique:
// Binary Search Tree (BST)
// Depth First Search (DFS)
// Recursion

// Approach:
// Traverse the tree recursively.
//
// Maintain the valid minimum and
// maximum range for every node.
//
// Return false if the current node
// violates the range.
//
// Recursively validate the left and
// right subtrees with updated bounds.

// TC: O(N)

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}