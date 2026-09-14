#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool bfs(int node, vector<int> adj[], vector<int> vis){
        vis[node] = true;

        queue<pair<int, int>> q;

        q.push({node, -1});

        while(!q.empty()){
            int node   = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = true;
                    q.push({adjNode, node});
                }
                else if(adjNode != parent) return true;
            }
        }

        return false;
    }

    bool dfs(int node, vector<int> adj[], vector<int>& vis, int parent){
        vis[node] = 1;

        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, adj, vis, node))
                    return true;
            }
            else if(adjNode != parent) return true;
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        bool ans = false;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                ans = bfs(i, adj, vis);
                // ans = dfs(i, adj, vis, -1);

                if(ans) return ans;
            }
        }

        return ans;
    }
};

// Technique:
// BFS
// Cycle Detection

// Approach:
// Traverse the graph using BFS while
// storing each node along with its
// parent.
//
// For every adjacent node:
// - If it is unvisited, mark it visited
//   and add it to the queue.
// - If it is already visited and is
//   not the parent, a cycle exists.
//
// Run BFS from every unvisited node
// to handle disconnected graphs.

// TC: O(V + E)

// SC: O(V)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}