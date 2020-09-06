//
//  581_shortesst_unsorted_continuous_subarray.cpp
//  leetcode_array
//
//  Created by Hadley on 20.04.20.
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
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> prev=nums;
        vector<int>range;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(prev[i]!=nums[i]){
                range.push_back(i);
                break;
            }
        }
        if(range.empty()){return 0;}
        for(int i=nums.size()-1;i>0;i--){
            if(prev[i]!=nums[i]){
                range.push_back(i);
                break;
            }
        }
        return range[1]-range[0]+1;
    }
};

class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>range;
        vector<int>range1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                range.push_back(i-1);
                break;
            }
        }
        if(range.empty()){return 0;}
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]>nums[i]){
                range.push_back(i);
                break;
            }
        }
        
        int max=*max_element(nums.begin()+range[0], nums.begin()+range[1]+1);
        int min=*min_element(nums.begin()+range[0], nums.begin()+range[1]+1);

        for(int i=0;i<nums.size();i++){
            if(min<nums[i]){
                range1.push_back(i);
                break;
            }
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(max>nums[i]){
                range1.push_back(i);
                break;
            }
        }
        return range1[1]-range1[0]+1;
    }
};
