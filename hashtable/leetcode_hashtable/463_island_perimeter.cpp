//
//  463_island_perimeter.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 15.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

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
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        auto m=grid.size();
        auto n=grid[0].size();
        int peri=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1)continue;
                if(j==0||grid[i][j-1]!=1)peri++;
                if(j==n-1||grid[i][j+1]!=1)peri++;
                if(i==0||grid[i-1][j]!=1)peri++;
                if(i==m-1||grid[i+1][j]!=1)peri++;
            }
        }
        return peri;
    }
};
