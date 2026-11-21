#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node, vector<vector<int>>& adj,
             vector<vector<int>>& newAdj,
             vector<int>& lastSeen, vector<int>& parent, string& s){
        
        int ch = s[node] - 'a';
        int prev = lastSeen[ch];

        if(prev != -1)     newAdj[prev].push_back(node);
        else if(node != 0) newAdj[parent[node]].push_back(node);  

        lastSeen[ch] = node;  

        for(int child : adj[node]){
            dfs(child, adj, newAdj, lastSeen, parent, s);
        }

        lastSeen[ch] = prev;      
    }

    int dfsSize(int node, vector<vector<int>>& newAdj, vector<int>& finalSize){
        int sizee = 1;

        for(int child : newAdj[node]){
            sizee += dfsSize(child, newAdj, finalSize);
        }

        return finalSize[node] = sizee;
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s){
        int n = s.size();

        vector<vector<int>> adj(n);
        vector<int> lastSeen(26, -1);
        vector<vector<int>> newAdj(n);
        vector<int> finalSize(n);

        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }

        dfs(0, adj, newAdj, lastSeen, parent, s);

        dfsSize(0, newAdj, finalSize);

        return finalSize;
    }
};

// Technique:
// Depth First Search (DFS)
// Tree Traversal
// Parent Tracking
// Subtree Size Calculation

// Approach:
// Build the original tree using the parent array.
//
// Perform DFS while maintaining the most recently
// visited ancestor for each character.
//
// If an ancestor with the same character exists,
// redirect the current node under that ancestor.
//
// Otherwise, retain its original parent.
//
// Backtrack the lastSeen array after processing
// each subtree to maintain the correct ancestor path.
//
// Finally, perform DFS on the modified tree
// to calculate the subtree size of every node.

// TC: O(N)

// O(N) => Build Original Adjacency List
// O(N) => Construct Modified Tree Using DFS
// O(N) => Calculate Subtree Sizes

// SC: O(N)

// O(N) => Original + Modified Adjacency Lists
// O(N) => Last Seen + Subtree Size Arrays
// O(N) => Recursive DFS Stack

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}