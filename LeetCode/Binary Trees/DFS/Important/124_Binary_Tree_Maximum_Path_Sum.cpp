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
    int findMaxpathSum(TreeNode* root, int &maxi){
        if(!root) return 0;

        int leftMaxPath  = max(0, findMaxpathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxpathSum(root->right, maxi));

        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);

        return root->val + max(leftMaxPath, rightMaxPath);
    }

public:
    int maxPathSum(TreeNode* root){
        int maxi = INT_MIN;

        findMaxpathSum(root, maxi);

        return maxi;
    }
};	

// Technique:
// Recursion
// Depth First Search (DFS)

// Approach:
// Recursively compute the maximum path
// sum that can be extended upwards from
// the left and right subtrees.
//
// Ignore negative path sums by treating
// them as zero since they reduce the
// overall path sum.
//
// At every node, compute the maximum
// path passing through it:
//
// Node Value + Left Contribution +
// Right Contribution
//
// Update the global maximum path sum
// using this value.
//
// Return the maximum extendable path:
//
// Node Value + Maximum(Left Contribution, Right Contribution)

// TC: O(N)
// N => No of Nodes

// SC: O(H)
// H => Height of the Tree (Recursive Stack)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}