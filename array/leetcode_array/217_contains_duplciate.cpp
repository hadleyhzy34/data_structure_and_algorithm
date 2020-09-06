//
//  217_contains_duplciate.cpp
//  leetcode_array
//
//  Created by Hadley on 18.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto num:nums){
            count[num]++;
            if(count[num]>1){
                return false;
            }
        }
        return true;
    }
};
