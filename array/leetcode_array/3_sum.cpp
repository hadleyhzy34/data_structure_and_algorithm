//
//  3_sum.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty())return {};
        sort(nums.begin(),nums.end());
        unordered_map<int, vector<vector<int>>>m;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                vector<int>temp={i,j};
                m[nums[i]+nums[j]].push_back(temp);
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++){
            if(i=0||nums[i]!=nums[i-1]){
                if(m.find(-nums[i])!=m.end()){
                    for(auto &x:m[-nums[i]]){
                        if(i<x[0]){
                            vector<int>temp={nums[i],nums[x[0]],nums[x[1]]};
                            res.push_back(temp);
                        }
                    }
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty())return {};
        sort(nums.begin(),nums.end());
        unordered_map<int, vector<vector<int>>>m;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                vector<int>temp={i,j};
                m[nums[i]+nums[j]].push_back(temp);
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++){
            if(i=0||nums[i]!=nums[i-1]){
                if(m.find(-nums[i])!=m.end()){
                    for(auto &x:m[-nums[i]]){
                        if(i<x[0]){
                            vector<int>temp={nums[i],nums[x[0]],nums[x[1]]};
                            res.push_back(temp);
                        }
                    }
                }
            }
        }
        return res;
    }
};
