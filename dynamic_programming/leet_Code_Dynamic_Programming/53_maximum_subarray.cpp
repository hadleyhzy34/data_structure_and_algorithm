//
//  53_maximum_subarray.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 24.09.20.
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
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        //key idea, if ith element would be the last element of subarray, then what would be the max sum value of it
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            if(i==0){
                dp[0]=nums[0];
            }else{
                dp[i]=max(nums[i],dp[i-1]+nums[i]);
            }
        }
        auto max_t=max_element(dp.begin(), dp.end());
        return *max_t;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int res = INT_MIN;

        for(int i=0;i<n;i++){
            if(i==0){
                dp[i]=nums[i];
            }else{
                dp[i]=max(dp[i-1]+nums[i],nums[i]);
            }
            if(dp[i]>res){
                res=dp[i];
            }
        }
        return res;
    }
};
