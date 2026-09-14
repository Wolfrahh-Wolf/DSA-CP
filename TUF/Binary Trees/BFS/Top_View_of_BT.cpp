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
public:
    vector<int> topView(TreeNode *root){
        vector<int> ans;

        if(!root) return ans;

        map<int, int> mpp;

        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front(); 
            q.pop();

            TreeNode* node = it.first;
            int line = it.second;

            if(mpp.find(line) == mpp.end()) mpp[line] = node->data;

            if(node->left)  q.push({node->left,  line - 1});
            if(node->right) q.push({node->right, line + 1});
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};

// Technique:
// Breadth First Search (BFS)
// Level Order Traversal

// Approach:
// Perform a level order traversal while
// tracking the vertical line (column) of
// each node.
//
// Store the first node encountered for
// every vertical line, since BFS visits
// nodes level by level and the first
// node is the topmost one.
//
// Finally, traverse the map from leftmost
// to rightmost vertical line and collect
// the stored node values.

// TC: O(N log N)
// N => No of Nodes

// SC: O(N)
// N => Queue + Map

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}