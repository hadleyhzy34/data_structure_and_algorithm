//
//  62_unique_paths.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 14.07.20.
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
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto row=grid.size();
        auto col=grid[0].size();
        
        int minSum[row][col];
        minSum[0][0]=grid[0][0];
        
        for(int i=1;i<row;i++){
            minSum[i][0]=minSum[i-1][0]+grid[i][0];
        }
        
        for(int j=1;j<col;j++){
            minSum[0][j]=minSum[0][j-1]+grid[0][j];
        }
         
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                minSum[i][j]=min(minSum[i-1][j],minSum[i][j-1])+grid[i][j];
            }
        }
        return minSum[row-1][col-1];
    }
};


