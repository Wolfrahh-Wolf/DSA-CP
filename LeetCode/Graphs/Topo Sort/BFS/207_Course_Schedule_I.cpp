#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &edge : prerequisites){
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;

            for(int next : adj[node]){
                indegree[next]--;

                if(indegree[next] == 0)
                    q.push(next);
            }
        }

        return cnt == numCourses;
    }
};

// Technique:
// BFS
// Topological Sort
// Kahn's Algorithm

// Approach:
// Build a directed graph where an
// edge u -> v means u must be
// completed before v.
//
// Calculate the indegree of every
// course.
//
// Start BFS with courses having
// indegree 0. After processing a
// course, reduce the indegree of
// its dependent courses.
//
// If all courses are processed,
// there is no cycle and all courses
// can be completed.

// TC: O(V + E)
// SC: O(V + E)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}