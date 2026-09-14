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
    TreeNode* getMax(TreeNode* root){
        if(!root) return nullptr;

        TreeNode* temp = root;

        while(temp->right) temp = temp->right;

        return temp;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return root;

        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else{
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if(!root->left){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(!root->right){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else{
                TreeNode* temp = getMax(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }

        return root;
    }
};

// Technique:
// Binary Search Tree (BST)
// Depth First Search (DFS)
// Recursion

// Approach:
// Traverse the BST recursively to
// locate the node to be deleted.
//
// If the node has no child, delete
// it and return nullptr.
//
// If the node has one child, replace
// it with its child and delete the
// current node.
//
// If the node has two children,
// replace its value with the maximum
// value from the left subtree.
//
// Recursively delete the predecessor
// node from the left subtree.

// TC: O(H)
// H => Height of the Tree

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}