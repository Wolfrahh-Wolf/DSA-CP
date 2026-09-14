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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;

        if(!p || !q) return false;

        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Technique:
// Recursion
// Depth First Search (DFS)

// Approach:
// Compare the corresponding nodes of
// both trees recursively.
//
// If both nodes are null, they are
// identical.
//
// If only one node is null or their
// values differ, the trees are not
// identical.
//
// Recursively compare the left and
// right subtrees.
//
// Return true only if both subtrees
// are identical.

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}