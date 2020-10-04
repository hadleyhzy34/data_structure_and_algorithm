//
//  33_search_in_rotated_sorted_array.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find the pivot
        int pivot=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                pivot=i+1;
            }
        }
        
        //retrieve original array
        reverse(nums.begin(),nums.begin()+pivot);
        reverse(nums.begin()+pivot,nums.end());
        reverse(nums.begin(), nums.end());
        
        //find the target
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                return (m+pivot)%nums.size();
            }else if(nums[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=int(nums.size()-1);
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                return m;
            }else{
                //if first half is in order
                if(nums[m]>=nums[l]){
                    //if target is in the range of first half
                    if(nums[m]>target&&target>=nums[l]){
                        r=m-1;
                    }else{
                        l=m+1;
                    }
                }else{//if first half is not in order
                    //if target is in the range of second half
                    if(nums[m]<target&&target<=nums[r]){
                        l=m+1;
                    }else{
                        r=m-1;
                    }
                }
            }
        }
        return -1;
    }
};
