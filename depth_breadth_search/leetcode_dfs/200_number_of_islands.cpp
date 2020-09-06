//
//  200_number_of_islands.cpp
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
    void countIslands(vector<vector<char>>& grid, int i, int j){
        if(i<0||j<0||i>grid.size()-1||j>grid[i].size()-1)return;
        if(grid[i][j]=='1'){
            grid[i][j]=count+'0';
            countIslands(grid, i-1, j);
            countIslands(grid, i, j-1);
            countIslands(grid, i+1, j);
            countIslands(grid, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        count=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    countIslands(grid, i, j);
                    count++;
                    // for(auto x:grid){
                    //     for(auto y:x){
                    //         cout<<y<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                }
            }
        }
        return count-2;
    }
private:
    int count;
};

