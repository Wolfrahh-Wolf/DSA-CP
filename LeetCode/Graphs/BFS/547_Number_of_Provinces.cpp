#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
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
            if(!vis[adjNode]){
                dfs(adjNode, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>&  isConnected){
        int V = isConnected.size();

        vector<vector<int>> adjLs(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                }
            }
        }

        int cnt = 0;

        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                bfs(i, adjLs, vis);
            }
        }

        return cnt;
    }
};

// Technique:
// BFS
// Graph Traversal

// Approach:
// Convert the adjacency matrix into
// an adjacency list.
//
// Traverse every unvisited node
// using BFS. Each new BFS traversal
// represents one connected component
// or province.
//
// Mark every visited node to avoid
// processing the same province again.

// TC: O(V²)

// SC: O(V²)


int main(){
    // Main Function placeholder for testing
    return 0;
}