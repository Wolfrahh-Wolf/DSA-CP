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
    long long int widthOfBinaryTree(TreeNode* root){
        long long int ans = 0;

        if(!root) return ans;

        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});

        while(!q.empty()){
            long long int size = q.size();

            long long int minIdx = q.front().second;
            
            long long int first = 0;
            long long int last  = 0;

            for(int i = 0; i < size; i++){
                long long int currIdx = q.front().second - minIdx;

                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = currIdx;
                if(i == size - 1) last = currIdx;

                // NOTE
                // Use Index as seen in Array Rep of Heaps
                if(node->left)  q.push({node->left,  currIdx * 2 + 1});
                if(node->right) q.push({node->right, currIdx * 2 + 2});
            }

            long long int width = last - first + 1;
            ans = max(ans, width);
        }

        return ans;
    }
};

// Technique:
// Breadth First Search (BFS)
// Level Order Traversal

// Approach:
// Perform a level order traversal while
// assigning each node an index based on
// its position in the complete binary
// tree representation.
//
// Normalize the indices at every level
// by subtracting the leftmost index to
// prevent integer overflow.
//
// Compute the width of the current level
// as the difference between the first
// and last normalized indices plus one.
//
// Update the maximum width over all
// levels.

// TC: O(N)
// N => No of Nodes

// SC: O(N)
// N => Queue

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}