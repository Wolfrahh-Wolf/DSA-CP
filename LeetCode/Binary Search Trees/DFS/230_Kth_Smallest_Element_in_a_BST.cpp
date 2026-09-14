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
    int kThSmallest(TreeNode* root, int k, int& curr){
        if(!root) return -1;

        int left =  kThSmallest(root->left, k, curr);
        if(left != -1) return left;

        if(++curr == k) return root->val;

        int right = kThSmallest(root->right, k, curr);
        if(right != -1) return right;

        return -1;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int curr = 0;
        return kThSmallest(root, k, curr);
    }
};

// NOTE: For kThlargest use Reverse Order Traversal 
//       Reverse Order => Right -> Root -> Left

// Technique:
// Binary Search Tree (BST)
// Depth First Search (DFS)
// Inorder Traversal
// Reverse Inorder Traversal
// Recursion

// Approach:
// Perform an inorder traversal to
// find the Kth smallest element.
//
// Maintain a counter and return the
// current node when the counter
// reaches K.
//
// Perform a reverse inorder traversal
// to find the Kth largest element.
//
// Return both the Kth smallest and
// Kth largest elements.

// TC: O(N)

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}