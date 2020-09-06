//
//  416_partition_equal_subset_sum.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 21.07.20.
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
    bool canPartition(vector<int>& nums) {
        int count=0;
        int sum=0;
        auto n=nums.size();
        for(auto &it:nums){
            count+=it;
        }
        if(count&1){
            return false;
        }else{
            sum=count/2;
        }
        
        int part[sum+1][n+1];
        memset(part, 0, sizeof(part));
        
        for(int i=1;i<=n;i++){
            part[0][i]=true;
        }
        for(int i=1;i<=sum;i++){
            part[i][0]=0;
        }
        
        for(int i=1;i<=sum;i++){
            for(int j=1;j<=n;j++){
                part[i][j]=part[i][j-1];
                if(i>=nums[j-1]){
                    part[i][j]=part[i][j]||part[i-nums[j-1]][j-1];
                }
            }
        }
        return part[sum][n];
    }
};
