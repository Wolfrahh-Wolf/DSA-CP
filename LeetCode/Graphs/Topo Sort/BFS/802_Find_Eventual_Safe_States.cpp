#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void topoSort(int V, vector<vector<int>> &adj, vector<int> &ans){
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++){
            for(int node : adj[i]){
                inDegree[node]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++){
            if(!inDegree[i]) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int it : adj[node]){
                inDegree[it]--;
                if(!inDegree[it]) q.push(it);
            }
        }
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph){
        vector<int> ans;

        int V = graph.size();

        vector<vector<int>> adjRev(V);

        for(int i = 0; i < V; i++){
            for(int node : graph[i]) 
                adjRev[node].push_back(i);
        }
        
        topoSort(V, adjRev, ans);

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// Technique:
// BFS
// Topological Sort
// Graph Reversal
// Kahn's Algorithm

// Intuition: 
// Reverse all edges so that terminal nodes 
// become nodes with in-degree 0.
// Kahn's BFS then starts from terminal nodes and 
// propagates backwards, identifying all nodes that 
// eventually reach a terminal node as safe.

// Approach:
// Reverse every directed edge so
// that the original terminal nodes
// become nodes with indegree 0.
//
// Apply Kahn's Algorithm on the
// reversed graph.
//
// Start BFS from nodes with
// indegree 0. These correspond to
// terminal nodes in the original graph.
//
// As nodes are processed, reduce the
// indegree of their neighbours in the
// reversed graph.
//
// Every node that gets processed is
// an eventual safe node.
//
// Finally, sort the result because
// the answer must be returned in
// increasing order.

// TC: O(V + E)

// SC: O(V)
// V => Visited, Path Visited, Safe Arrays
// O(V) => Recursion Stack

// TC: O(V + E) + O(V log V) => O(V + E)
// O(V + E)   => Topological Sort
// O(V log V) => Sorting safe nodes

// SC: O(V + E)
// O(V + E) => Reversed adjacency list + Indegree

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}