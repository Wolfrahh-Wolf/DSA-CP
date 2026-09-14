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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return root;

        if(root->val < p->val && root->val < q->val) 
            return lowestCommonAncestor(root->right, p, q);

        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,  p, q);

        return root; // (root->val == p || root->val == q)
    }
};

// Technique:
// Binary Search Tree (BST)
// Lowest Common Ancestor (LCA)
// Recursion

// Approach:
// Traverse the BST recursively.
//
// If both target nodes are smaller
// than the current node, move to the
// left subtree.
//
// If both target nodes are greater
// than the current node, move to the
// right subtree.
//
// Otherwise, the current node is the
// Lowest Common Ancestor.

// TC: O(H)
// H => Height of the Tree

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}