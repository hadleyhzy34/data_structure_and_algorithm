//
//  547_friend_circles.cpp
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
    
    int findCircleNum(vector<vector<int>>& M) {
        vector<vector<int>>adj(M.size());
        vector<bool>visited(M.size(),false);
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[i].size();j++){
                if(M[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<M.size();i++){
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
