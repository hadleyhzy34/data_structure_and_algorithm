//
//  1_two_sum.cpp
//  leetcode_array
//
//  Created by Hadley on 16.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums.at(i)+nums.at(j)==target){
                    return vector<int> {i,j};
                }
            }
        }
        return vector<int> {0};
    }
};
