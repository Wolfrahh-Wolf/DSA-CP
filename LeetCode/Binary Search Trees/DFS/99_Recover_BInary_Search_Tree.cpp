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
    stack<TreeNode*> st;

private:
    void pushAll(TreeNode* temp){
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
    }

public:
    BSTIterator(TreeNode* root){
        pushAll(root);
    }
    
    bool hasNext(){
        return !st.empty();
    }
    
    TreeNode* next(){
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);

        return temp;
    }
};

class Solution{
private:
    TreeNode* first  = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last   = nullptr; 

public:
    void recoverTree(TreeNode* root) {
        BSTIterator it(root);

        TreeNode* prev = nullptr;


        while(it.hasNext()){
            TreeNode* curr = it.next();

            if(prev && prev->val > curr->val){
                if(!first){
                    first  = prev;
                    middle = curr;
                }
                else{
                    last = curr;
                }
            }

            prev = curr;
        }

        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val);
    }
};

// Technique:
// Binary Search Tree (BST)
// Inorder Traversal
// Stack

// Approach:
// Traverse the BST in inorder using
// the iterator.
//
// Identify the first violation where
// the previous node is greater than
// the current node.
//
// Store the first and middle nodes
// during the first violation.
//
// Store the last node if a second
// violation is encountered.
//
// Swap the appropriate node values
// to restore the BST.

// TC: O(N)

// SC: O(H)
// H => Height of the Tree (Iterator Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}