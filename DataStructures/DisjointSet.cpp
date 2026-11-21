#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int> rank;
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1, 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool find(int u, int v){
        return (findUPar(u) == findUPar(v));
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Technique:
// Disjoint Set Union (DSU)
// Path Compression
// Union by Rank
// Union by Size

// Approach:
// Initially, every node is its own parent.
//
// findUPar() finds the ultimate parent using
// path compression to flatten the tree.
//
// unionByRank() attaches the shorter-rank tree
// under the taller-rank tree.
//
// unionBySize() attaches the smaller tree
// under the larger tree.
//
// Both union operations keep the trees shallow,
// providing nearly constant amortized time.

// TC: O(α(N)) per operation

// O(α(N)) => findUPar() with Path Compression
// O(α(N)) => unionByRank() / unionBySize()

// SC: O(N)

// O(N) => Parent Array
// O(N) => Rank Array
// O(N) => Size Array
// O(log N) => Recursion Stack in findUPar()

// Verdict: Optimal


int main(){
    // Main Function placeholder for testing
    
    DisjointSet ds(5);
    
    return 0;
}