//
//  153_find_minimum_in_rotated_sorted_array.cpp
//  leetcode_array
//
//  Created by Hadley on 08.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1||nums[0]<nums[nums.size()-1])return nums[0];
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<nums[r]){
                if(m==0||nums[m]<nums[m-1]){
                    return nums[m];
                }else{
                    r=m-1;
                }
            }else{
                if(nums[m]>nums[m+1]){
                    return nums[m+1];
                }else{
                    l=m+1;
                }
            }
        }
        return l;
    }
};
