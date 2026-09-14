#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool isSafe(int node, int col, vector<int> &colours, vector<vector<int>> &adj){
        for(int neighbor : adj[node]){
            if(colours[neighbor] == col) return false;
        }

        return true;
    }

    bool solve(int node, int &m, int &n, vector<int> &colours, vector<vector<int>> &adj){
        if(node == n) return true;

        for(int col = 1; col <= m; col++){
            if(isSafe(node, col, colours, adj)){
                colours[node] = col;

                if(solve(node + 1, m, n, colours, adj)) return true;

                colours[node] = 0;
            }
        }

        return false;
    }

public:
    bool graphColoring(vector<vector<int>>& edges, int m, int n){
        vector<vector<int>> adj(n);

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colours(n, 0);

        return solve(0, m, n, colours, adj);
    }
};

// Technique:
// Backtracking

// Approach:
// Build the adjacency list from the given edges.
//
// Process nodes one by one and try assigning
// every color from 1 to M.
//
// Before assigning a color, check whether any
// adjacent node already has the same color.
//
// If the color is valid:
// - Assign it.
// - Recurse for the next node.
//
// If the recursive call fails,
// backtrack by removing the color.
//
// If all nodes are successfully colored,
// return true.
//
// If no valid coloring exists,
// return false.

// TC: O(M^N)
// N => No of Nodes
// M => No of Colors
//
// For every node, up to M colors
// may be attempted.

// SC: O(N)
// Recursive stack + Color array

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}