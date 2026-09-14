#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int node, vector<vector<int>>& adjLs, vector<int>& vis){
        vis[node] = 1;

        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int i = q.front();
            q.pop();

            for(auto& adjNode : adjLs[i]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis){
        vis[node] = 1;

        for(auto& adjNode : adjLs[node]){
            if(!vis[adjNode])
                dfs(adjNode, adjLs, vis);
        }
    }

public:
    int findNumberOfComponent(int V, vector<vector<int>>& edges){
        int E = edges.size();

        vector<vector<int>> adjLs(V);

        for(int i = 0; i < E; i++){
            adjLs[edges[i][0]].push_back(edges[i][1]);
            adjLs[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(V, 0);

        int cnt = 0;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;

                bfs(i, adjLs, vis);
                //dfs(i, adjLs, vis);
            }
        }

        return cnt;
    }
};

// Technique:
// BFS / DFS
// Graph Traversal

// Approach:
// Convert the edge list into an
// adjacency list.
//
// Traverse every unvisited node
// using BFS or DFS.
//
// Each new traversal starts from a
// new connected component, so
// increment the component count.
//
// Mark every visited node to avoid
// processing the same component
// again.

// TC: O(V + E)
// SC: O(V + E)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}