//
//  78_subsets.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 22.08.20.
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
    void subCombination(vector<int>& nums, int l, vector<int>&subset, vector<vector<int>>&res){
        if(l>=nums.size())return;
        for(int i=l;i<nums.size();i++){
            subset.push_back(nums[i]);
            res.push_back(subset);
            subCombination(nums, i+1,subset,res);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>res={{}};
        subCombination(nums, 0, subset, res);
        return res;
    }
};













class Solution2 {
public:
    void subsets(int index,vector<int>&nums, vector<int>&subset, vector<vector<int>>&res){
        if(index==nums.size())return;
        for(int i=index;i<nums.size();i++){
            subset.push_back(nums[i]);
            res.push_back(subset);
            subsets(index+1, nums, subset, res);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>res={{}};
        subsets(0, nums, subset, res);
        return res;
    }
};
