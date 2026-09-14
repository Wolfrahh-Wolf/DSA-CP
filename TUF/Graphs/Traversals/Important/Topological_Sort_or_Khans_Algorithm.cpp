#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;

        for(int it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, st);
        }

        st.push(node);
    }

    void bfs(int V, vector<int> adj[], vector<int> &ans){
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++){
            for(int node : adj[i]){
                inDegree[node]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
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
    vector<int> topoSort(int V, vector<int> adj[]){
        stack<int> st;
        vector<int> vis(V, 0);
        vector<int> ans;

        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(i, adj, vis, st);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    
        // bfs(V, adj, ans);

        return ans;
    }
};

// ===> DFS

// Technique:
// DFS
// Topological Sort

// Approach:
// Perform DFS from every unvisited
// vertex.
//
// Explore all adjacent vertices
// before pushing the current vertex
// into the stack.
//
// This ensures every dependency is
// placed before the current vertex
// in the final ordering.
//
// Finally, pop elements from the
// stack to obtain the topological
// ordering.

// TC: O(V + E)

// SC: O(V)
// Visited array + recursion stack
// + topological stack.

// Verdict: Optimal



// ===> BFS

// Technique:
// BFS
// Topological Sort
// Kahn's Algorithm

// Approach:
// Calculate the indegree of every
// vertex.
//
// Push all vertices with indegree 0
// into the queue.
//
// Process each vertex and reduce the
// indegree of its adjacent vertices.
//
// Whenever an adjacent vertex gets
// indegree 0, push it into the queue.
//
// The order in which vertices are
// removed from the queue forms the
// topological ordering.

// TC: O(V + E)

// SC: O(V)
// Indegree array + queue + output.

// Verdict: Optimal 

int main(){
    // Main Function placeholder for testing
    return 0;
}