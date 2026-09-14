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
    bool symmetry(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;

        if(!left || !right) return false;

        if(left->val != right->val) return false;

        return symmetry(left->left, right->right) &&
               symmetry(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root){
        if(!root) return true;

        return symmetry(root->left, root->right);
    }
};

// Technique:
// Depth First Search (DFS)
// Recursion

// Approach:
// Compare the left and right subtrees
// simultaneously.
//
// At every step, both nodes must exist
// and have the same value.
//
// Recursively compare the left child of
// the left subtree with the right child
// of the right subtree, and vice versa.
//
// If all corresponding mirrored pairs
// satisfy these conditions, the tree is
// symmetric.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}