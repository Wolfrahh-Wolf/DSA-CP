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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();

            vector<int> level(size);

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                int idx = leftToRight ? i : (size - 1 - i);

                level[idx] = node->val;

                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }

            leftToRight = !leftToRight;

            ans.push_back(level);
        }

        return ans;
    }
};

// Technique:
// Breadth First Search (BFS)
// Level Order Traversal

// Approach:
// Perform a level order traversal using
// a queue.
//
// For every level, create a vector to
// store the node values.
//
// If traversing from left to right,
// insert values from the beginning.
//
// Otherwise, insert them from the end
// by computing the appropriate index.
//
// Toggle the traversal direction after
// processing each level and append the
// current level to the answer.

// TC: O(N)
// N => No of Nodes

// SC: O(N)
// N => Queue + Result Storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}