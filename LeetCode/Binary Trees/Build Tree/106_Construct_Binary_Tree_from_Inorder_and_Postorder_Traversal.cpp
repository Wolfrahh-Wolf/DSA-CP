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
    TreeNode* buildSubTree(vector<int>& postorder, int postStart, int postEnd, 
                           vector<int>& inorder,  int inStart,  int inEnd, 
                           unordered_map<int, int>& inMap){

        if(postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root->left  = buildSubTree(postorder, postStart, postStart + numsLeft - 1, 
                                  inorder, inStart, inRoot - 1, inMap);

        root->right = buildSubTree(postorder, postStart + numsLeft, postEnd - 1,
                                  inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        unordered_map<int, int> inMap;

        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildSubTree(postorder, 0, postorder.size() - 1,
                                      inorder,   0, inorder.size() - 1, inMap);


        return root; 
    }
};

// Technique:
// Recursion
// Divide and Conquer
// Hashing

// Approach:
// The last element of the current
// postorder range represents the root.
//
// Locate the root in the inorder
// traversal using a hash map to divide
// the tree into left and right
// subtrees.
//
// Recursively construct the left and
// right subtrees by passing the
// corresponding postorder and inorder
// ranges.
//
// Return the constructed root node.

// TC: O(N)
// N => No of Nodes

// SC: O(N)
// N => Hash Map + Recursive Stack

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}