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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q) return root;

        TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;  
        if(left)  return left;
        if(right) return right;

        return nullptr;
    }
};

// Technique:
// Recursion
// Depth First Search (DFS)

// Approach:
// Recursively search for both target
// nodes in the left and right subtrees.
//
// If the current node matches either
// target, return it immediately.
//
// If both recursive calls return a
// non-null node, the current node is
// the Lowest Common Ancestor.
//
// Otherwise, propagate the non-null
// result upwards. If neither subtree
// contains a target node, return null.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}