//
//  162_find_peak_element.cpp
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
    int search(vector<int>& nums,int l,int r){
        if(l==r)return l;
        int m=l+(r-l)/2;
        if(nums[m]>nums[m+1]){
            return search(nums, l, m);
        }else{
            return search(nums, m+1, r);
        }
    }
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size()-1);
    }
};
