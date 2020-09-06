//
//  485_max_consecutive_ones.cpp
//  leetcode_array
//
//  Created by Hadley on 20.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                cur++;
            }else{
                cur=0;
            }
            if(cur>max)max=cur;
        }
        return max;
    }
};
