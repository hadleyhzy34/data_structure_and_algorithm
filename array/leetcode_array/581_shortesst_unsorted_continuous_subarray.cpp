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
                pair<int,int>range;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                range.first=i-1;
                break;
            }
        }

        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]<nums[i-1]){
                range.second=i;
                break;
            }
        }
        
        if(range.first==0&&range.second==0)return 0;
        cout<<range.first<<" "<<range.second<<endl;
        
        int min=*min_element(nums.begin()+range.first,nums.begin()+range.second+1);
        int max=*max_element(nums.begin()+range.first,nums.begin()+range.second+1);
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>min){
                range.first=i;
                break;
            }
        }

        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]<max){
                range.second=i;
                break;
            }
        }
        return range.second-range.first+1;
    }
};
