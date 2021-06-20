//
//  494_target_sum.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 21.07.20.
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
    int findTargetSumWays(vector<int>& nums, int S) {
        auto n=nums.size();
        
        vector<int> r={-nums[0],nums[0]};
        vector<vector<int>> res={r};
        
        for(int i=1;i<n;i++){
            vector<int> temp;
            for(auto it:res[i-1]){
                temp.push_back(it+nums[i]);
                temp.push_back(it-nums[i]);
            }
            res.push_back(temp);
        }
        return std::count(res[n-1].begin(), res[n-1].end(), S);
    }
};

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
//        if(nums.empty()){
//            if(S==0){
//                return 1;
//            }else{
//                return 0;
//            }
//        }
//        if(nums.size()==1&&(nums[0]==S||nums[0]==-S)){
//            return 1;
//        }else if(nums.size()==1&&nums[0]!=S&&nums[0]!=-S){
//            return 0;
//        }
        if(nums.empty())return 0;
        if(nums.size()==1&&nums[0]==S&&nums[0]==-S){
                    return 2;
                }else if(nums.size()==1&&nums[0]!=S&&nums[0]!=-S){
                    return 0;
                }else if(nums.size()==1&&(nums[0]==S||nums[0]==-S)){
                    return 1;
                }
        vector<int>sub(nums.begin(),nums.end()-1);
        return findTargetSumWays(sub, S-nums[nums.size()-1])+findTargetSumWays(sub, S+nums[nums.size()-1]);
    }
};
