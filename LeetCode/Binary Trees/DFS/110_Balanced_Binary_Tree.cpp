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
    int dfsHeight(TreeNode *root){
        if(!root) return 0;

        int leftHeight  = dfsHeight(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode *root){
        return dfsHeight(root) != -1;
    }
};

// Technique:
// Recursion
// Depth First Search (DFS)

// Approach:
// Recursively compute the height of the
// left and right subtrees.
//
// If either subtree is already unbalanced,
// immediately propagate -1 upwards.
//
// If the height difference between the
// left and right subtrees exceeds 1,
// return -1.
//
// Otherwise, return the height of the
// current subtree.
//
// The tree is balanced if the final
// returned height is not -1.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}