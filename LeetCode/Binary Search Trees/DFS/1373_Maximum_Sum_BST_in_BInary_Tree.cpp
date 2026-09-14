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

class NodeValue{
public:
    int minNode;
    int maxNode;
    int sum;

    NodeValue(int minNode, int maxNode, int sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution{
private:
    int maxBSTSum = 0;

    NodeValue maxSumBSTHelper(TreeNode* root){
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

        NodeValue left  = maxSumBSTHelper(root->left);
        NodeValue right = maxSumBSTHelper(root->right);

        if(left.maxNode < root->val && root->val < right.minNode){
            int currSum = left.sum + right.sum + root->val;

            maxBSTSum = max(maxBSTSum, currSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        return NodeValue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root){
        maxSumBSTHelper(root);

        return maxBSTSum;
    }
};

// Technique:
// Binary Tree
// Binary Search Tree (BST)
// Postorder Traversal
// Depth First Search (DFS)
// Recursion

// Approach:
// Traverse the tree in postorder.
//
// Collect the minimum value,
// maximum value and sum of the
// left and right subtrees.
//
// If the current subtree satisfies
// the BST property, compute its sum
// and update the maximum BST sum.
//
// Otherwise, mark the subtree as
// invalid so it cannot be merged
// into its parent.

// TC: O(N)

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}