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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};

// Technique:
// BFS - Level Order Traversal using Queue

// Approach:
// Use a queue to perform level-order traversal of the binary tree.
// For each level, process all nodes currently in the queue.
// Store values of nodes level-wise in a temporary vector.
// Push left and right children of each node into the queue.
// Add each level's vector to the final answer.

// TC: O(N)
// N => Number of nodes in the tree
// SC: O(N)
// N => Queue storage in worst case

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}