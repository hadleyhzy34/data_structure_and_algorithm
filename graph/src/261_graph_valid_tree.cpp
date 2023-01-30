#include <iostream>
#include <vector>
#include <queue>>

class Solution {
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges) {
        std::queue<int> node;
        std::vector<int> degrees(n,0);
        std::vector<std::vector<int>> adj(n);

        if(edges.empty()&&n==1)return true;
        if(edges.size() < n-1)return false;
        for(auto edge:edges){
            degrees[edge[0]]++;
            degrees[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // std::cout<<"test"<<std::endl;
        int res = 0;

        for(int i = 0; i < n; i++){
            if(degrees[i]==1){
                node.push(i);
                res++;
            }
            if(degrees[i]==0)return false;
        }
        
        while(!node.empty()){
            int cur = node.front();
            node.pop();

            for(int i=0;i<adj[cur].size();i++){
                degrees[adj[cur][i]]--;
                if(degrees[adj[cur][i]]==1){
                    node.push(adj[cur][i]);
                    res++;
                }
            }
        }
        return res==n;
    }

};
