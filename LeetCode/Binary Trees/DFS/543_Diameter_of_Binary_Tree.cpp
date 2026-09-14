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
    int dfsDiameter(TreeNode* root, int &diameter){
        if(!root) return 0;
    
        int leftHeight  = dfsDiameter(root->left, diameter);
        int rightHeight = dfsDiameter(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root){
        int diameter = 0;

        dfsDiameter(root, diameter);

        return diameter;
    }
};

// Technique:
// Recursion
// Depth First Search (DFS)

// Approach:
// Recursively compute the height of the
// left and right subtrees.
//
// At every node, the longest path passing
// through it is:
//
// Left Subtree Height + Right Subtree Height
//
// Update the maximum diameter using this
// value while computing subtree heights.
//
// Return the height of the current subtree
// to the parent.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}