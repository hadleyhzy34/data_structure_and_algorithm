//
//  70_climbing_stairs.cpp
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
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        vector<pair<int, int>> robMoney(nums.size(),make_pair(0, 0));
        robMoney[0].first=nums[0];
        robMoney[0].second=0;
        for(int i=1;i<nums.size();i++){
            robMoney[i].first=robMoney[i-1].second+nums[i];
            robMoney[i].second=max(robMoney[i-1].second, robMoney[i-1].first);
        }
        return max(robMoney[nums.size()-1].first,robMoney[nums.size()-1].second);
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        int dp[nums.size()];
        int m=nums[0];
        for(int i=0;i<nums.size();i++){
            if(i==0){
                dp[i]=nums[0];
            }else if(i==1){
                dp[i]=nums[1];
            }else if(i==2){
                dp[i]=nums[i]+dp[0];
            }else{
                dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
            }
            m=max(m,dp[i]);
        }
        return m;
    }
};



