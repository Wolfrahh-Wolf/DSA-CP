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
    bool reversed;

private:
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node = (reversed) ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse){
        this->reversed = isReverse;
        pushAll(root);
    }
    
    bool hasNext(){
        return !st.empty();
    }
    
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reversed) pushAll(temp->right);
        else pushAll(temp->left);

        return temp->val;
    }
};

class Solution{	
public:
    bool findTarget(TreeNode* root, int k){
        if(!root) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int low  = l.next();
        int high = r.next();

        while(low < high){
            int sum = low + high;

            if(sum == k) return true;
            else if(sum < k) low = l.next();
            else high = r.next();
        }
        
        return false;
    }
};

// Technique:
// Binary Search Tree (BST)
// Inorder Traversal
// Reverse Inorder Traversal
// Two Pointers
// Stack

// Approach:
// Initialize two BST iterators.
//
// Traverse the BST in inorder to
// obtain the next smallest element.
//
// Traverse the BST in reverse inorder
// to obtain the next largest element.
//
// Compare the sum of both values
// with the target.
//
// Move the appropriate iterator until
// the pointers meet or a pair is
// found.

// TC: O(N)

// SC: O(H)
// H => Height of the Tree (Iterator Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}