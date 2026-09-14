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
	string findOrder(string dict[], int N, int K){
        string ans = "";

        vector<vector<int>> adj(K);

        for(int i = 0; i < N - 1; i++){
            string str1 = dict[i];
            string str2 = dict[i + 1]; 

            int len  = min(str1.size(), str2.size());

            for(int j = 0; j < len; j++){
                if(str1[j] != str2[j]){
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> topo;

        topoSort(K, adj, topo);

        for(int ch : topo)
            ans += char(ch + 'a');

		return ans;
	}
};

// Technique:
// BFS
// Topological Sort
// Kahn's Algorithm

// Approach:
// Build a directed graph by comparing
// adjacent words.
//
// The first differing character gives
// the ordering relation between them.
//
// Calculate the indegree of every vertex
// and apply Kahn's Algorithm.
//
// The resulting topological order gives
// the character ordering.

// TC: O(N × L + K + E)

// O(N × L) => Compare adjacent words
// O(K + E) => Topological Sort

// SC: O(K + E)

// O(K + E) => Adjacency List
// O(K) => Indegree Array + Queue + Topological Order

// Verdict: Optimal


int main(){
    // Main Function placeholder for testing
    return 0;
}