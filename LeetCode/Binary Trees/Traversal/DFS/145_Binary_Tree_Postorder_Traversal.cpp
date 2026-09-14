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
    void postOrderTraversal(TreeNode* root, vector<int>& ans){
        if(!root) return;

        postOrderTraversal(root->left, ans);
        postOrderTraversal(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrderTraversal(root, ans);

        return ans;
    }
};

// Technique:
// Recursion: Postorder (Tree Traversal)

// Approach:
// Use recursion to perform postorder traversal of the binary tree.
// Traverse left subtree, then right subtree,
// and finally visit the current node.
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
