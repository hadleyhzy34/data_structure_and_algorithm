//
//  283_move_zeros.cpp
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
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(auto it=nums.begin();it!=nums.end();it++){
            // cout<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<" "<<*it<<endl;
             if(!*it){
                 nums.erase(it);it--;
                 count++;
             }
         }
         for(int i=0;i<count;i++){
             nums.push_back(0);
         }
    }
};

//solution2

