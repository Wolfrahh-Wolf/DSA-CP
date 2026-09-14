#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution{
public:
    vector<int> succPredBST(TreeNode* root, int key){
        TreeNode* pred =  nullptr;
        TreeNode* succ = nullptr;
        TreeNode* curr = root;

        while(curr){
            if(key < curr->data){
                succ = curr;
                curr = curr->left;
            }

            else if(key > curr->data){
                pred = curr;
                curr = curr->right;
            }

            else{
                if(curr->left){
                    TreeNode* temp = curr->left; 

                    while(temp->right) temp = temp->right;
                    pred = temp;
                }
                if(curr->right){
                    TreeNode* temp = curr->right; 

                    while(temp->left) temp = temp->left;
                    succ = temp;
                }
                break;
            }
        }

        int predVal = pred ? pred->data : -1;
        int succVal = succ ? succ->data : -1;

        return {predVal, succVal};
    }
};

// Technique:
// Binary Search Tree (BST)
// Iterative Traversal

// Approach:
// Traverse the BST to locate the
// given key while maintaining the
// potential predecessor and successor.
//
// If the key is found, find the
// predecessor as the rightmost node
// of the left subtree.
//
// Find the successor as the leftmost
// node of the right subtree.
//
// Return the predecessor and
// successor values.

// TC: O(H)
// H => Height of the Tree

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}