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
    void buildMap(unordered_map<TreeNode*, TreeNode*>& parentMap,
                  TreeNode*& startNode,
                  TreeNode* root, int start){
        if(!root) return;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) startNode = node;

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
    int amountOfTime(TreeNode* root, int start){
        int time = 0;

        if(!root) return time;

        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode;
        buildMap(parentMap, startNode, root, start);

        unordered_set<TreeNode*> infected;
        queue<TreeNode*> q;

        if(!startNode) return 0;
        q.push(startNode);
        infected.insert(startNode);

        while(!q.empty()){
            int size = q.size();
            bool spread = false;
            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();
                q.pop();

                if(node->left && infected.find(node->left) == infected.end()){
                    q.push(node->left);
                    infected.insert(node->left);
                    spread = true;
                }

                if(node->right && infected.find(node->right) == infected.end()){
                    q.push(node->right);
                    infected.insert(node->right);
                    spread = true;
                }

                if(parentMap.find(node) != parentMap.end() &&  
                infected.find(parentMap[node]) == infected.end()){
                    q.push(parentMap[node]);
                    infected.insert(parentMap[node]);
                    spread = true;
                }
            }
            
            if(spread) time++;
        }

        return time;
    }
};

// Technique:
// Breadth First Search (BFS)
// Graph Traversal

// Approach:
// Perform a BFS traversal to build a
// mapping from every node to its parent
// and locate the starting node.
//
// Starting from the infected node,
// perform another BFS while treating the
// tree as an undirected graph by
// considering the left child, right
// child, and parent as adjacent nodes.
//
// Maintain a visited set to ensure each
// node is infected only once.
//
// Increment the time after each level
// only if the infection spreads to at
// least one new node.
//
// The total time required to infect the
// entire tree is the answer.

// TC: O(N)
// N => No of Nodes

// SC: O(N)
// N => Parent Map + Visited Set + Queue

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}