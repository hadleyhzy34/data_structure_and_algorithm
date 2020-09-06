//
//  153_find_minimum_in_rotated_sorted_array.cpp
//  binary_search
//
//  Created by Hadley on 08.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1||nums[0]<nums[nums.size()-1])return nums[0];
        int l=0;
        auto n=nums.size();
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<nums[r]){
                if(mid==0||nums[mid]<nums[mid-1]){
                    return nums[mid];
                }else{
                    r=mid-1;
                }
            }else{
                if(nums[mid]>nums[mid+1]){
                    return nums[mid+1];
                }else{
                    l=mid+1;
                }
            }
        }
        return 0;
    }
};
