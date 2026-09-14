#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool bfs(int start, vector<vector<int>> &graph, vector<int> &colour){
        queue<int> q;
        q.push(start);

        colour[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int adj : graph[node]){
                if(colour[adj] == -1){
                    colour[adj] = !colour[node];
                    q.push(adj);
                }
                else if(colour[adj] == colour[node]) return false;
            }
        }

        return true;
    }

    bool dfs(int node, vector<vector<int>> &graph, vector<int> &colour){
        for(int adj : graph[node]){
            if(colour[adj] == -1){
                colour[adj] = !colour[node];

                if(!dfs(adj, graph, colour)) return false;
            }
            else if(colour[adj] == colour[node]) return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph){
        int V = graph.size();

        vector<int> colour (V, -1);

        for(int i = 0; i < V; i++){
            if(colour[i] == -1){
                if(!bfs(i, graph, colour)) return false;

                // colour[i] = 0;
                // if(!dfs(i, graph, colour)) return false;
            }
        }

        return true;
    }
};

// Technique:
// BFS / DFS
// Graph Coloring
// Bipartite Graph

// Approach:
// Assign one of two colors to each
// vertex using BFS.
//
// For every uncolored adjacent node,
// assign the opposite color and add
// it to the queue.
//
// If an adjacent node already has
// the same color as the current node,
// the graph is not bipartite.
//
// Run BFS from every uncolored node
// to handle disconnected components.

// TC: O(V + E)

// SC: O(V + E)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}