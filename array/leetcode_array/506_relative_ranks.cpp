//
//  506_relative_ranks.cpp
//  leetcode_array
//
//  Created by Hadley on 29.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int one=0,two=0,three=0;
        int oneIdx=-1, twoIdx=-1, threeIdx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>one){
                three=two;
                threeIdx=twoIdx;
                two=one;
                twoIdx=oneIdx;
                one=nums[i];
                oneIdx=i;
            }else if(nums[i]<one&&nums[i]>two){
                three=two;
                threeIdx=twoIdx;
                two=nums[i];
                twoIdx=i;
            }else if(nums[i]<two&&nums[i]>three){
                three=nums[i];
                threeIdx=i;
            }
        }
        vector<string>res;
        for(int i=0;i<nums.size();i++){
            res.push_back(to_string(i));
        }
        if(oneIdx!=-1)res[oneIdx]="Gold Medal";
        if(twoIdx!=-1)res[twoIdx]="Silver Medal";
        if(threeIdx!=-1)res[threeIdx]="Bronze Medal";
        
        return res;
    }
};
