#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector<int> topoSort(int V, vector<vector<int>>& adjLs){
        vector<int> inDegree(V, 0);

        for(auto adj : adjLs){
            for(int node : adj){
                inDegree[node]++;
            }
        }

        queue<int> q;
        vector<int> topo;

        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int it : adjLs[node]){
                inDegree[it]--;
                if(!inDegree[it]) q.push(it);
            }
        }

        return topo;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adjLs(numCourses);

        for(auto &edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            // Building Directed Adjacency List
            adjLs[v].push_back(u);
        }

        vector<int> topo = topoSort(numCourses, adjLs);

        if(topo.size() == numCourses) return topo;

        return {};
    }
};

// Technique:
// BFS
// Topological Sort
// Kahn's Algorithm

// Approach:
// Build a directed graph where
// prerequisite → course.
//
// Calculate the indegree of every
// course.
//
// Add all courses with indegree 0
// to the queue.
//
// Process each course and reduce
// the indegree of its dependent
// courses.
//
// If a dependent course reaches
// indegree 0, add it to the queue.
//
// If all courses are processed,
// the topological ordering is valid.
//
// If fewer than V courses are
// processed, a cycle exists, so
// return an empty array.

// TC: O(V + E)
// V = Number of courses
// E = Number of prerequisites

// SC: O(V + E)
// Adjacency list + indegree array
// + queue.

// Verdict: Optimal


int main(){
    // Main Function placeholder for testing
    return 0;
}