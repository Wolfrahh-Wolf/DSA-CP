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
    vector<vector<int>> verticalTraversal(TreeNode* root){
        vector<vector<int>> ans;

        if(!root) return ans;

        // Vertical -> Level -> Min Heap of Node Values
        // nodesMap[x][y] = Min Heap of all node values
        // x -> Vertical (Column), y -> Level (Row)

        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> nodesMap;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;

            int x = curr.second.first;
            int y = curr.second.second;

            nodesMap[x][y].push(node->val);

            if(node->left)  q.push({node->left,  {x - 1, y + 1}});
            if(node->right) q.push({node->right, {x + 1, y + 1}});
        }

        for(auto &vertical : nodesMap){
            vector<int> col;

            for(auto &level : vertical.second){
                while(!level.second.empty()){
                    col.push_back(level.second.top());
                    level.second.pop();
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};

// Technique:
// Breadth First Search (BFS)
// Sorting

// Approach:
// Perform a level order traversal while
// assigning each node its vertical (x)
// and level (y) coordinates.
//
// Store nodes in a nested map where:
//
// Vertical -> Level -> Min Heap
//
// The maps automatically maintain the
// required vertical and level ordering,
// while the min heap sorts nodes having
// the same position by value.
//
// Finally, traverse the nested map and
// collect the nodes column by column to
// construct the vertical order traversal.

// TC: O(N log N)
// N => No of Nodes

// SC: O(N)
// N => Queue + Nested Maps + Min Heaps

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}