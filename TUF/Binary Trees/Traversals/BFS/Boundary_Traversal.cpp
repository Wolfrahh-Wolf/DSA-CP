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
private:
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }

    void addLeftBoundary(TreeNode* root, vector<int> &ans){
        TreeNode* curr = root->left;

        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->data);

            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addRightBoundary(TreeNode* root, vector<int> &ans){
        TreeNode* curr = root->right;

        vector<int> temp;

        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);

            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }

        for(int i = temp.size() - 1; i >= 0; i--){
            ans.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode* root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }

        if(root->left)  addLeaves(root->left,  ans);
        if(root->right) addLeaves(root->right, ans);
    }

public:
    vector<int> boundary(TreeNode* root){
        vector<int> ans;

        if(!root) return ans;

        if(!isLeaf(root)) ans.push_back(root->data);

        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};

// Technique:
// Tree Traversal
// Depth First Search (DFS)

// Approach:
// Traverse the boundary of the tree in
// anti-clockwise order.
//
// First, add the root (if it is not a
// leaf).
//
// Then, traverse the left boundary while
// excluding leaf nodes.
//
// Next, collect all leaf nodes using a
// DFS traversal from left to right.
//
// Finally, traverse the right boundary
// while excluding leaf nodes, store the
// nodes temporarily, and append them in
// reverse order to maintain the required
// traversal sequence.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)
// + O(H) Temporary Storage for Right Boundary

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}