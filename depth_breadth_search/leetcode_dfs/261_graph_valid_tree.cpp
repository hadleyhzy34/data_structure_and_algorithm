//
//  261_graph_valid_tree.cpp
//  leetcode_dfs
//
//  Created by Hadley on 26.08.20.
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
    bool checkCycle(vector<vector<int>>&adj, int i, vector<bool>&visited, int parent){
        visited[i]=true;
        bool temp=true;
        for(int j=0;j<adj[i].size();j++){
            // cout<<i<<" "<<adj[i][j]<<endl;
            if(visited[adj[i][j]]==true){
                if(adj[i][j]!=parent)return false;
            }else{
                // cout<<i<<" "<<adj[i][j]<<endl;
                temp=temp&&checkCycle(adj, adj[i][j], visited, i);
            }
        }
        return temp;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // for(auto x:visited){
        //     if(x==false)return false;
        // }
        bool res=checkCycle(adj, 0, visited, -1);
        for(auto x:visited){
            if(x==false)return false;
        }
        return res;
    }
};
