//
//  523_continuous_subarray_sum.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 22.07.20.
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<=1)return false;
        auto n=nums.size();
        
        vector<int>sum;
        sum.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            sum.push_back(nums[i]+sum[i-1]);
        }
        
        for(int i=0;i+1<n;i++){
            for(int j=i+1;j<n;j++){
                int val=sum[j]-sum[i]+nums[i];
                if(val!=0&&k==0){
                    continue;
                }else if((k==0&&val==0)||val%k==0){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<=1)return false;
        auto n=nums.size();
        
        unordered_map<int, int> c;
        
        vector<int>sum;
        sum.push_back(nums[0]);
        if(k!=0){
            int mod=nums[0]%k;
            c[mod]=1;
        }
        
        for(int i=1;i<n;i++){
            sum.push_back(nums[i]+sum[i-1]);
            if(nums[i]==nums[i-1]&&nums[i]==0){
                return true;
            }
            if(k==0)continue;
            int mod=(nums[i]+sum[i-1])%k;
            if(mod==0)return true;
            if(c[mod]==0){
                c[mod]=i+1;
            }else{
                if((i+1-c[mod])>1)return true;
            }
        }
        return false;
    }
};
