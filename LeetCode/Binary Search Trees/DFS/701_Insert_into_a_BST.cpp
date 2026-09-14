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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        if(val < root->val) root->left = insertIntoBST(root->left, val);
        else if(val > root->val) root->right = insertIntoBST(root->right, val);

        return root;
    }
};

// Technique:
// Binary Search Tree (BST)
// Depth First Search (DFS)
// Recursion

// Approach:
// Traverse the BST recursively.
//
// Move to the left or right subtree
// based on the value to be inserted.
//
// Create a new node when a null
// position is reached.
//
// Return the updated root after
// insertion.

// TC: O(H)
// H => Height of the Tree

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}