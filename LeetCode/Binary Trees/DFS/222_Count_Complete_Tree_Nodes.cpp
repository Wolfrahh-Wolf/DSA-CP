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
    void inorder(TreeNode* root, int& cnt){
        if(!root) return;

        cnt++;

        inorder(root->left, cnt);
        inorder(root->right, cnt);
    }
public:
    int countNodes(TreeNode* root) { 
        if(!root) return 0;

        int cnt = 0;

        inorder(root, cnt);

        return cnt;
    }
};

// Technique:
// Depth First Search (DFS)
// Recursion

// Approach:
// Traverse every node of the binary
// tree using DFS.
//
// Increment the count for each visited
// node.
//
// Return the total count after the
// traversal is complete.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal (General Binary Tree)
// Better Solution Exists for Complete Binary Tree

int main(){
    // Main Function placeholder for testing
    return 0;
}