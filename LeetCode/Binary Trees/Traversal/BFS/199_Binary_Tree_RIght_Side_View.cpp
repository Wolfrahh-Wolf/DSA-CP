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

public:
    vector<int> rightSideView(TreeNode* root){
        vector<int> ans;

        vector<vector<int>> levelOrd = levelOrder(root);

        for(auto level : levelOrd){
            ans.push_back(level.back());
        }

        return ans;
    }
};

// Technique:
// Breadth First Search (BFS)
// Level Order Traversal

// Approach:
// Perform a level order traversal of the
// binary tree.
//
// For every level, the last node
// represents the node visible from the
// right side.
//
// Collect the last node from each level
// and return the resulting sequence.

// TC: O(N)
// N => No of Nodes

// SC: O(N)
// N => Queue + Level Order Storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}