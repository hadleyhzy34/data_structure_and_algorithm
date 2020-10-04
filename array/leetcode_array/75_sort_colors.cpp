//
//  75_sort_colors.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red_cnt=0;
        int white_cnt=0;
        int blue_cnt=0;
        for(auto &x:nums){
            if(x==0){
                red_cnt++;
            }else if(x==1){
                white_cnt++;
            }else{
                blue_cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i<red_cnt){
                nums[i]=0;
            }else if(i<red_cnt+white_cnt){
                nums[i]=1;
            }else{
                nums[i]=2;
            }
        }
    }
};
