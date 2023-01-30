#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
        bool validTree(int n, std::vector<std::vector<int>>& edges) {
        std::vector<bool> visited(n, false);
        std::vector<std::vector<int>> adj(n);
        std::queue<int> nodes;
        std::vector<int> degrees(n);
        int visited_nodes = 0;

        if(n==1&&edges.size()==0){
            return true;
        }
        if(edges.size()<n-1){
            return false;
        }
        
        for(auto e:edges){
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
            ++degrees[e[0]];
            ++degrees[e[1]];
        }
        
        //push lead nodes to queue
        for(int i = 0; i < n; i++){
            if(degrees[i]==1){
                nodes.push(i);
            }
        }
        
        while(!nodes.empty()){
            int cur = nodes.front();
            nodes.pop();
            visited[cur] = true;
            visited_nodes++;

            //std::cout<<"courses visited: "<<cur<<std::endl;
            for(int i = 0; i < adj[cur].size(); i++){
                // if(adj[cur][i]==cur)continue;
                degrees[adj[cur][i]]--;
                // if(visited[adj[cur][i]]){
                //     std::cout<<cur<<" "<<adj[cur][i]<<" "<<visited[adj[cur][i]]<<std::endl;
                //     return false;
                // }
                if(degrees[adj[cur][i]]==1){
                    nodes.push(adj[cur][i]);
                }
            }
        }
        // std::cout<<"vn: "<<visited_nodes<<std::endl;
        return visited_nodes == n?true:false;
    }
};

