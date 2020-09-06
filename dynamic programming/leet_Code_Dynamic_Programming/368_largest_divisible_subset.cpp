//
//  368_largest_divisible_subset.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 20.07.20.
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto n=nums.size();
        
        int max=0;
        int index=0;
        
        for(int i=0;i<n;i++){
            int c=0;
            for(auto x:nums){
                if(nums[i]%x==0)c++;
            }
            if(c>max){
                max=c;
                index=i;
            }
        }
        
        vector<int>res;
        for(auto x:nums){
            if(nums[index]%x==0)res.push_back(x);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty())return {};
        sort(nums.begin(),nums.end());
        auto n=nums.size();
        
        vector<vector<int>>L;
        
        int maxSub=0;
        int index=0;
        
        for(int i=0;i<n;i++){
            L.push_back({nums[i]});
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&L[j].size()+1>L[i].size()){
                    L[i]=L[j];
                    L[i].push_back(nums[i]);
                }
            }
            if(L[i].size()>maxSub){
                maxSub=L[i].size();
                index=i;
            }
        }
        return L[index];
    }
};

