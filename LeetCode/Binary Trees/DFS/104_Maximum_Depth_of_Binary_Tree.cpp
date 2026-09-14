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
    int maxDepth(TreeNode* root){
        if(!root) return 0;

        int leftDepth  = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};

// Technique:
// Recursion
// Depth First Search (DFS)

// Approach:
// Recursively compute the maximum depth
// of the left and right subtrees.
//
// The depth of the current node is:
//
// 1 + Maximum(Left Subtree Depth,
//             Right Subtree Depth)
//
// Return 0 when a null node is reached.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}