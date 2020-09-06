//
//  1_two_sum.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 15.08.20.
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
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target)return {i,j};
            }
        }
        return {};
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto n=nums.size();
        vector<int> ori=nums;
        sort(nums.begin(), nums.end());
        int l=0,r=n-1;
        vector<int>index;
        vector<int>res(2,0);
        while(l<r){
            if(nums[l]+nums[r]==target){
                index.push_back(l);
                index.push_back(r);
                break;
            }else if(nums[l]+nums[r]<target){
                l++;
            }else{
                r--;
            }
        }
        
        int i=0,j=0;
        while(i<n&&j<2){
            if(ori[i]==nums[index[j]]){
                res[j]=i;
                i++;j++;
            }else{
                i++;
            }
        }
        return res;
    }
};



class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>map;
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])==map.end()){
                map[nums[i]]=i;
            }else{
                return {map[target-nums[i]],i};
            }
        }
        return {};
    }
};

