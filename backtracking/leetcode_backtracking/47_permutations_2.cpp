//
//  47_permutations_2.cpp
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
    void permutation(vector<int>&nums,int index, vector<int>temp){
        if(index>=nums.size()){
            res.push_back(nums);
        }
        for(int i=0;i<temp.size();i++){
            if(record[temp[i]]<=0)continue;
            nums[index]=temp[i];
            record[temp[i]]--;
            permutation(nums, index+1, temp);
            record[temp[i]]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto x:nums){
            record[x]++;
        }
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        temp.resize(std::distance(temp.begin(), std::unique(temp.begin(), temp.end())));
        permutation(nums, 0, temp);
        return res;
    }
    
private:
    vector<vector<int>>res;
    unordered_map<int, int>record;
};

class Solution2 {
    public:
void permu(vector<int> nums, int l, vector<vector<int>>&res){
            if(l==nums.size()-1){
                res.push_back(nums);
            }
            for(int i=l;i<nums.size();i++){
                if(i==l||nums[i]!=nums[l]){
                    swap(nums[l],nums[i]);
                    permu(nums, l+1, res);
                    // swap(nums[l],nums[i]);
                }
            }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        permu(nums, 0, res);
        return res;
    }
};
