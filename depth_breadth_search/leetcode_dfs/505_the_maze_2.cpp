//
//  505_the_maze_2.cpp
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
    bool isValid(vector<int>& start , vector<vector<int>>& maze)
    {
        if(start[0] >= 0 && start[0] < maze.size() && start[1] >= 0 && start[1] < maze[0].size() && maze[start[0]][start[1]] != 1)
        {
            return true;
        }
        
        return false;
    }
    
    int foundPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, unordered_map<string , pair<int , int>>& dir,vector<vector<int>>& vis, int distance)
    {
        if(!isValid(start , maze) || vis[start[0]][start[1]])return -1;
        
        if(start == destination)return distance;

        vis[start[0]][start[1]] = 1;
        int min_distance=INT_MAX;
        
        for(auto it = dir.begin() ; it != dir.end() ; it++)
        {
            pair<int,int> delta = it->second;
            vector<int> newPos = start;
            int count=0;
            
            while(isValid(newPos , maze))
            {
                newPos[0] = newPos[0] + delta.first;
                newPos[1] = newPos[1] + delta.second;
                count++;
            }
            // get last valid position
                newPos[0] = newPos[0] - delta.first;
                newPos[1] = newPos[1] - delta.second;
            //get new numbers of cells to be moved
                count--;
            
            int temp=foundPath(maze, newPos, destination, dir,vis,distance+count);
            
            if(isValid(newPos , maze) && temp!=-1)min_distance=min(min_distance,temp);
        }
        
        return (min_distance==INT_MAX)?-1:min_distance;
    }
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        unordered_map<string , pair<int , int>> dir;
        dir["LEFT"]  = make_pair(0 , -1);
        dir["RIGHT"] = make_pair(0 , 1);
        dir["UP"]    = make_pair(-1 , 0);
        dir["DOWN"]  = make_pair(1 , 0);
        
        vector<vector<int>> vis(maze.size() , vector<int> (maze[0].size() , 0) );
        return foundPath(maze , start , destination, dir, vis, 0);
    }
};
