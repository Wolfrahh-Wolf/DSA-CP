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

class BSTIterator{
    stack<TreeNode*> myStack;

private:
    void pushAll(TreeNode* node){
        while(node){
            myStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root){
        pushAll(root);
    }
    
    bool hasNext(){
        return !myStack.empty();
    }
    
    int next(){
        TreeNode* node = myStack.top();
        myStack.pop();
        pushAll(node->right);

        return node->val;
    }
};

// Technique:
// Binary Search Tree (BST)
// Inorder Traversal
// Stack

// Approach:
// Push all the left nodes starting
// from the root onto the stack.
//
// For each next() call, pop the top
// node from the stack.
//
// Push all the left nodes of the
// popped node's right subtree.
//
// Repeat until the stack becomes
// empty.

// TC:
// Constructor: O(H)
// hasNext(): O(1)
// next(): O(1) Amortized

// H => Height of the Tree

// SC: O(H)
// H => Stack

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}