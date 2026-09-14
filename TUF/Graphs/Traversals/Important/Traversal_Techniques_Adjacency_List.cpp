#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node,vector<vector<int>> &adjLs, vector<int> &vis, vector<int> &ans){
        vis[node] = 1;

        ans.push_back(node);

        for(auto it : adjLs[node]){
            if(!vis[it]) dfs(it, adjLs, vis, ans);
        }
    }

    void bfs(int node,vector<vector<int>> &adjLs, vector<int> &vis, vector<int> &ans){
        vis[node] = 1;

        queue<int> q;

        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adjLs[node]){
                if(!vis[it]){
                    vis[it] = 1;

                    q.push(it);
                }
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<vector<int>> edges){
        vector<int> vis(V, 0);

        vector<int> ans;

        vector<vector<int>> adjLs(V);

        for(auto &edge : edges){
            adjLs[edge[0]].push_back(edge[1]);
            adjLs[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(i, adjLs, vis, ans);
        }

        return ans;
    }
    
    vector<int> bfsOfGraph(int V, vector<vector<int>> edges){
        vector<int> vis(V, 0);

        vector<int> ans;

        vector<vector<int>> adjLs(V);

        for(auto &edge : edges){
            adjLs[edge[0]].push_back(edge[1]);
            adjLs[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < V; i++){
            if(!vis[i]) bfs(i, adjLs, vis, ans);
        }

        return ans;
    }
};

// Technique:
// DFS / BFS
// Graph Traversal

// Approach:
// Convert the edge list into an
// adjacency list.
//
// Traverse every unvisited vertex.
// DFS recursively explores the graph,
// while BFS uses a queue.
//
// Start a new traversal whenever an
// unvisited vertex is found, so that
// disconnected components are also
// covered.

// TC: O(V + E)
// Each vertex and edge is processed once.

// SC: O(V + E)
// Adjacency list + visited array,
// answer and traversal space.


int main(){
    // Main Function placeholder for testing
    return 0;
}