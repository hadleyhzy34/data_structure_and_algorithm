#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    void checkCycle(int idx, std::vector<std::vector<int>>& adj, std::vector<int>& visited){
        visited[idx] = true;
        for(int i = 0; i < adj[idx].size(); i++){
            if(visited[adj[idx][i]])continue;
            checkCycle(adj[idx][i], adj, visited);
        }
    }

    bool validTree(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        std::vector<int> visited(n);
        
        if(edges.size()!=n-1)return false;
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        checkCycle(0, adj, visited);
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
        return true;
    }
};
