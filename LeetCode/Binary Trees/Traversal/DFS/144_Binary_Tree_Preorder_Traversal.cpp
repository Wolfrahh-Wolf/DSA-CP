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
    void preOrderTraversal(TreeNode* node, vector<int>& ans){
        if(!node){
            return;
        }

        ans.push_back(node->val);
        preOrderTraversal(node->left, ans);
        preOrderTraversal(node->right, ans);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrderTraversal(root, ans);
        return ans;
    }
};

// Technique:
// Recursion (Pre-Order Tree Traversal)

// Approach:
// Use recursion to perform preorder traversal of the binary tree.
// Visit the current node first, then recursively traverse
// the left subtree followed by the right subtree.
// Store node values in the result vector during traversal.

// TC: O(N)
// N => Number of nodes in the tree
// SC: O(H)
// H => Height of the tree (recursive stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}