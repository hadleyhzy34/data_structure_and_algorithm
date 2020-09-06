//
//  33_search_in_rotated_sorted_array.cpp
//  binary_search
//
//  Created by Hadley on 05.08.20.
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
    int search(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }else{
                return -1;
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
                return (m+breaking_point+1)%nums.size();
            }else if(nums[m]>target){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return -1;
    }
};
