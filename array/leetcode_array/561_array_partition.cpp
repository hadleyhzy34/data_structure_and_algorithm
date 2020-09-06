//
//  561_array_partition.cpp
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
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int output=0;
        for(int i=0;i<nums.size();i+=2){
            output+=min(nums[i],nums[i+1]);
        }
        return output;
    }
};
