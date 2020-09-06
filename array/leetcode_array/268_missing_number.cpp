//
//  268_missing_number.cpp
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

class Solution268 {
public:
    int missingNumber(vector<int>& nums) {
        int sum = static_cast<int>((1+nums.size())*nums.size()/2);
        for(auto num:nums){
            sum-=num;
        }
        return sum;
    }
};
