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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

       if(!root) return ans;

       TreeNode* curr = root; 

        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == nullptr){
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

// Technique:
// Threaded Binary Tree
// Morris Traversal
// Inorder Traversal

// Approach:
// Traverse the tree without using
// recursion or an explicit stack.
//
// If the current node has no left
// child, visit it and move to its
// right child.
//
// Otherwise, find its preorder
// predecessor.
//
// If the predecessor is not threaded,
// visit the current node, create a
// temporary thread to it, and move to
// the left subtree.
//
// If the thread already exists, remove
// it and move to the right subtree.

// TC: O(N)
// N => No of Nodes

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}