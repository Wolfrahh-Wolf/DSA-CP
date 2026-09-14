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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;

        while(temp){
            if(val == temp->val) return temp;

            if(val > temp->val) temp = temp->right;
            else temp = temp->left;
        }

        return nullptr;
    }
};

// Technique:
// Binary Search Tree (BST)
// Iterative Search

// Approach:
// Start from the root node.
//
// Compare the current node value
// with the target value.
//
// Move to the left or right child
// based on the comparison.
//
// Return the node if found,
// otherwise return nullptr.

// TC: O(H)
// H => Height of the Tree

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}