//
//  81_search_in_rotated_sorted_array_2.cpp
//  leetcode_array
//
//  Created by Hadley on 04.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=int(nums.size()-1);
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                return m;
            }else{
                //if first half is in order
                if(nums[m]>nums[l]){
                    //if target is in the range of first half
                    if(nums[m]>target&&target>=nums[l]){
                        r=m-1;
                    }else{
                        l=m+1;
                    }
                }else if(nums[m]<nums[l]){//if first half is not in order
                    //if target is in the range of second half
                    if(nums[m]<target&&target<=nums[r]){
                        l=m+1;
                    }else{
                        r=m-1;
                    }
                }else{
                    l=m+1;
                }
            }
        }
        return -1;
    }
};
