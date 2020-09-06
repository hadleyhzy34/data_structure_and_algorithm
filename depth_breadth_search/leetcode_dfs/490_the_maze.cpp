//
//  490_the_maze.cpp
//  leetcode_dfs
//
//  Created by Hadley on 28.08.20.
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
    bool checkPath(vector<vector<int>>&maze, vector<int>& cur, vector<int>&destination, vector<vector<bool>>visited){
        if(visited[cur[0]][cur[1]]==true)return false;
        if(cur==destination)return true;
        visited[cur[0]][cur[1]]=true;
        int r=cur[1]+1, l=cur[1]-1, u=cur[0]-1, d=cur[0]+1;
        while(r<maze[0].size()&&maze[cur[0]][r]!=1)r++;
        vector<int>pos={cur[0],r-1};
        if(pos[1]!=cur[1]){
            if(checkPath(maze, pos, destination, visited))return true;
        }
        
        while(l>=0&&maze[cur[0]][l]!=1)l--;
        pos={cur[0],l+1};
        if(pos[1]!=cur[1]){
            if(checkPath(maze, pos, destination, visited))return true;
        }
        
        while(u>=0&&maze[u][cur[1]]!=1)u--;
        pos={u+1,cur[1]};
        if(pos[0]!=cur[0]){
            if(checkPath(maze, pos, destination, visited))return true;
        }
        
        while(d<maze.size()&&maze[d][cur[1]]!=1)d++;
        pos={d-1,cur[1]};
        if(pos[0]!=cur[1]){
            if(checkPath(maze, pos, destination, visited))return true;
        }
        
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>>visited(maze.size(),vector<bool>(maze[0].size(),false));
        return checkPath(maze, start, destination, visited);
    }
};
