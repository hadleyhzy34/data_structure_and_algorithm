//
//  136_single_number.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 07.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(auto it=nums.begin()+1;it!=nums.end();it++){
            *nums.begin()=*nums.begin()^*it;
        }
        return *nums.begin();
    }
};
