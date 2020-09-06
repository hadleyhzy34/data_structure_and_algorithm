//
//  491_increasing_subsequences.cpp
//  leetcode_dfs
//
//  Created by Hadley on 26.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
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
#include <filesystem>
#include <dirent.h>
using namespace std;

class Solution {
public:
    void subSequencesFind(vector<int>& nums, vector<int>& subset, int start_index, int end_index, int length){
            unordered_map<int, int>map;
            for(int i=end_index+1;i<nums.size();i++){
                if(map.find(nums[i])!=map.end()){
                    continue;
                }else if(nums[i]>=nums[end_index]){
                    subset.push_back(nums[i]);
                    map[nums[i]]++;
                    if(subset.size()>1)res.push_back(subset);
                    subSequencesFind(nums, subset, start_index, i, length+1);
                    subset.pop_back();
                }
            }
        }
    
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            unordered_map<int, int>map;
            for(int i=0;i<nums.size()-1;i++){
                if(map.find(nums[i])==map.end()){
                    map[nums[i]]++;
                    vector<int>subset={nums[i]};
                    subSequencesFind(nums, subset, i, i, 1);
                }else{
                    continue;
                }
//                while(i<nums.size()-1&&nums[i]==nums[i+1])i++;
            }
            return res;
        }
    private:
        vector<vector<int>> res;
};
