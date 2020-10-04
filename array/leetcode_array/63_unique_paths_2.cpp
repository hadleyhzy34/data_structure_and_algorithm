//
//  63_unique_paths_2.cpp
//  leetcode_array
//
//  Created by Hadley on 04.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//
#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    if(obstacleGrid[0][0]==1){
                        return 0;
                    }else{
                        dp[0][0]=1;
                    }
                }else{
                    if(obstacleGrid[i][j]==1){
                        dp[i][j]=0;
                    }else{
                        dp[i][j]=0;
                        if(i>0){
                            dp[i][j]+=dp[i-1][j];
                        }
                        if(j>0){
                            dp[i][j]+=dp[i][j-1];
                        }
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
