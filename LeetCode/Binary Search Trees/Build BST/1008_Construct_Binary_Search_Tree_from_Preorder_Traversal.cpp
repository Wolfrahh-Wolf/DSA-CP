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
    TreeNode* buildBST(vector<int>& preorder, int& idx, int upperBound){
        if(idx == preorder.size() || preorder[idx] > upperBound) return nullptr;

        TreeNode* node = new TreeNode(preorder[idx++]);

        node->left  = buildBST(preorder, idx, node->val);
        node->right = buildBST(preorder, idx, upperBound);

        return node;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return buildBST(preorder, idx, INT_MAX);
    }
};

// Technique:
// Binary Search Tree (BST)
// Preorder Traversal
// Recursion

// Approach:
// Traverse the preorder array using
// an index.
//
// Create a node if the current value
// is within the valid upper bound.
//
// Recursively construct the left
// subtree with the current node as
// the new upper bound.
//
// Recursively construct the right
// subtree using the existing upper
// bound.

// TC: O(N)

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}