//
//  323_number_of_connected_components_in_an_undirected_graph.cpp
//  leetcode_dfs
//
//  Created by Hadley on 27.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;

class Solution {
public:
    void checkCycle(vector<vector<int>>&adj, int i, vector<bool>&visited, int parent){
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            // cout<<i<<" "<<adj[i][j]<<endl;
            if(visited[adj[i][j]]==true){
                if(adj[i][j]!=parent)continue;
            }else{
                // cout<<i<<" "<<adj[i][j]<<endl;
                checkCycle(adj, adj[i][j], visited, i);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }else{
                checkCycle(adj, i, visited, -1);
                count++;
            }
        }
        return count;
    }
};
