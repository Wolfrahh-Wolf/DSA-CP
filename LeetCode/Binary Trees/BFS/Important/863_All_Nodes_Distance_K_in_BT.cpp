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
    void buildParentMap(unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* root){
        if(!root) return;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parentMap[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        vector<int> ans;

        if(!root) return ans;

        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(parentMap, root);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        
        int currDis = 0;

        q.push(target);
        visited.insert(target);

        while(!q.empty()){
            if(currDis == k){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }

                return ans;
            }

            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if(parentMap.find(node) != parentMap.end() &&  
                visited.find(parentMap[node]) == visited.end()){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            
            currDis++;
        }

        return ans;
    }
};

// Technique:
// Breadth First Search (BFS)
// Graph Traversal

// Approach:
// Perform a BFS traversal to build a
// mapping from every node to its parent.
//
// Starting from the target node, perform
// another BFS while treating the tree as
// an undirected graph by considering the
// left child, right child, and parent as
// adjacent nodes.
//
// Maintain a visited set to avoid
// revisiting nodes.
//
// When the current distance becomes K,
// all nodes remaining in the queue are
// exactly K distance away from the
// target. Collect and return them.

// TC: O(N)
// N => No of Nodes

// SC: O(N)
// N => Parent Map + Visited Set + Queue

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}