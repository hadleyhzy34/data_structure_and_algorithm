//
//  152_maximum_product_subarray.cpp
//  leetcode_array
//
//  Created by Hadley on 08.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;


//brute force, time limited exceeded
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=INT_MIN;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n));

        for(int i=0;i<nums.size();i++){
            for(int l=1;i+l-1<nums.size();l++){
                if(l==1){
                    dp[i][i]=nums[i];
                }else{
                    dp[i][i+l-1]=dp[i][i+l-2]*nums[i+l-1];
                }
                if(dp[i][i+l-1]>res){
                    res=dp[i][i+l-1];
                }
            }
        }
        return res;
    }
};

//dp
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=nums[0];
        int n=int(nums.size());

        vector<int> dp_min(n);
        vector<int> dp_max(n);
        dp_min[0]=nums[0];
        dp_max[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            dp_min[i]=min(nums[i],min(dp_min[i-1]*nums[i],dp_max[i-1]*nums[i]));
            dp_max[i]=max(nums[i],max(dp_max[i-1]*nums[i],dp_min[i-1]*nums[i]));
            res=max(res,dp_max[i]);
        }
        return res;
    }
};


