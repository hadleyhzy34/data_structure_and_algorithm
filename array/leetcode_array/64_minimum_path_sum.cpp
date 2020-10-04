//
//  64_minimum_path_sum.cpp
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
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,(vector<int>(n,INT_MAX)));
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>0){
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+grid[i][j]);
                }
                if(i>0){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+grid[i][j]);
                }
            }
        }
        
        
        return dp[m-1][n-1];
    }
};
