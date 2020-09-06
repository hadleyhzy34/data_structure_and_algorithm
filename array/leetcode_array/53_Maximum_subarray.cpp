//
//  Maximum_subarray.cpp
//  leetcode_array
//
//  Created by Hadley on 17.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution53 {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> local_maximum(nums.size());
        local_maximum[0] = nums[0];
        if(nums.size()==1){return nums[0];}
        for(int i=1;i<nums.size();i++){
            local_maximum[i] = max(nums[i], nums[i]+local_maximum[i-1]);
        }
        
        vector<int>::iterator max_test = max_element(local_maximum.begin(), local_maximum.end());
        return *max_test;
    }
};
