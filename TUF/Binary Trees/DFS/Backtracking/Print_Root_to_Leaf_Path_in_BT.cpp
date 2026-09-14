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
    void dfsAllPath(TreeNode* root, vector<vector<int>>& ans, vector<int>& path){
        if(!root) return;

        path.push_back(root->data);

        if(!root->left && !root->right) ans.push_back(path);
        else{
            dfsAllPath(root->left,  ans, path);
            dfsAllPath(root->right, ans, path);
        }

        path.pop_back();
    }

public:
    vector<vector<int>> allRootToLeaf(TreeNode* root){
        vector<vector<int>> ans;
        vector<int> path;

        dfsAllPath(root, ans, path);

        return ans;
    }
};

// Technique:
// Depth First Search (DFS)
// Backtracking

// Approach:
// Traverse the tree recursively while
// maintaining the current root-to-node
// path.
//
// Add the current node to the path.
//
// If a leaf node is reached, store the
// current path in the answer.
//
// Otherwise, continue exploring the left
// and right subtrees.
//
// Backtrack by removing the current node
// before returning to the parent.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)
// + Current Path Storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}