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
    void flatten(TreeNode* root){
        TreeNode* curr = root;

        while(curr){
            if(curr->left){
                TreeNode* leftSubTree = curr->left;

                while(leftSubTree->right){
                    leftSubTree = leftSubTree->right;
                }

                leftSubTree->right = curr->right;
                curr->right = curr->left;
                curr->left  = nullptr;
                
                curr = curr -> right;
            }
            else curr = curr->right;
        }
    }
};

// Technique:
// Morris Traversal
// Pointer Manipulation

// Approach:
// Traverse the tree iteratively.
//
// For every node having a left subtree,
// find the rightmost node of the left
// subtree.
//
// Connect the original right subtree to
// the rightmost node.
//
// Move the left subtree to the right,
// set the left child to null, and
// continue traversing through the right
// child until the tree is flattened.

// TC: O(N)
// N => No of Nodes

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}