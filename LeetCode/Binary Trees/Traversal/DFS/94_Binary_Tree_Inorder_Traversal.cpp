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
private:
    void inOrderTraversal(TreeNode* root, vector<int>& ans){
        if(!root) return;

        inOrderTraversal(root->left, ans);
        ans.push_back(root->val);
        inOrderTraversal(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrderTraversal(root, ans);

        return ans;
    }
};

// Technique:
// Recursion (Tree Traversal)

// Approach:
// Use recursion to perform inorder traversal of the binary tree.
// Traverse left subtree, then visit current node,
// and finally traverse the right subtree.
// Store node values in the result vector during traversal.

// TC: O(N)
// N => Number of nodes in the tree
// SC: O(H)
// H => Height of the tree (recursive stack)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}