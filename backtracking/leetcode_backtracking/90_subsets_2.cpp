//
//  90_subsets_2.cpp
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
            for(int j=1;j<=record[nums[i]];j++){
                vector<int>t(j,nums[i]);
                subset.insert(subset.end(), t.begin(),t.end());
                res.push_back(subset);
                subCombination(nums, i+1, subset, res);
                subset.erase(subset.end()-j,subset.end());
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for(auto x:nums){
            record[x]++;
        }
        
        sort(nums.begin(),nums.end());
        nums.resize(std::distance(nums.begin(), std::unique(nums.begin(), nums.end())));
        
        vector<int> subset;
        vector<vector<int>>res={{}};
        subCombination(nums, 0, subset, res);
        return res;
    }
private:
    unordered_map<int, int>record;
};


class Solution2 {
public:
    void subCombination(vector<int>& nums, int l, vector<int>&subset, vector<vector<int>>&res){
        if(l>=nums.size())return;
        for(int i=l;i<nums.size();i++){
            subset.push_back(nums[i]);
            if(find(res.begin(),res.end(),subset)!=res.end()){
                subset.pop_back();
                continue;
            }
            res.push_back(subset);
            subCombination(nums, i+1,subset,res);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        vector<vector<int>>res={{}};
        subCombination(nums, 0, subset, res);
        return res;
    }
};
