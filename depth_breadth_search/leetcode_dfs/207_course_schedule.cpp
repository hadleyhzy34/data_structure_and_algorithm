//
//  207_course_schedule.cpp
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
    bool checkCycle(vector<vector<int>>&adj, int i, vector<bool>&visited){
        visited[i]=true;
        bool temp=true;
        for(int j=0;j<adj[i].size();j++){
            // cout<<i<<" "<<adj[i][j]<<endl;
            if(visited[adj[i][j]]==true){
                return false;
            }else{
                // cout<<i<<" "<<adj[i][j]<<endl;
                temp=temp&&checkCycle(adj, adj[i][j], visited);
            }
        }
        return temp;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(int i=0;i<prerequisites.size();i++){
            //list of courses that are prerequisites of course pre[i][0]
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<n;i++){
            if(!checkCycle(adj, i, visited))return false;
        }
        return true;
    }
};

class Solution2 {
public:
    enum visit{visiting, visited, unvisited};
    bool checkCycle(vector<vector<int>>&adj, int i, vector<visit>&v){
        v[i]=visiting;
        for(int j=0;j<adj[i].size();j++){
            // cout<<i<<" "<<adj[i][j]<<endl;
            if(v[adj[i][j]]==visiting){
                // cout<<"its already visited"<<i<<" "<<adj[i][j]<<endl;
                return true;
            }else{
                // cout<<i<<" "<<adj[i][j]<<endl;
                if(v[adj[i][j]]==unvisited&&checkCycle(adj, adj[i][j], v))return true;
            }
        }
        v[i]=visited;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<visit>v(numCourses,unvisited);
        for(int i=0;i<prerequisites.size();i++){
            //list of courses that are prerequisites of course pre[i][0]
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<n;i++){
            if(v[i]==visited)continue;
            if(checkCycle(adj, i, v))return false;
        }
        return true;
    }
};
