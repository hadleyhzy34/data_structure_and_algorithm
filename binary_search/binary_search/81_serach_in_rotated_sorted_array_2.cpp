//
//  81_serach_in_rotated_sorted_array_2.cpp
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
    bool search(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        if(nums.size()==1){
            if(nums[0]==target){
                return true;
            }else{
                return false;
            }
        }
        //check breaking point
        int breaking_point=nums.size()-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])breaking_point=i;
        }
        //rotate back
        reverse(nums.begin(), nums.begin()+breaking_point+1);
        reverse(nums.begin()+breaking_point+1, nums.end());
        reverse(nums.begin(), nums.end());
        
        //binary search
        int l=0;
        auto n=nums.size();
        int r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                return true;;
            }else if(nums[m]>target){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return false;
    }
};
