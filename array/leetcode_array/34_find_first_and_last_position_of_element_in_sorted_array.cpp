//
//  34_find_first_and_last_position_of_element_in_sorted_array.cpp
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
    vector<int> searchRange(vector<int>& nums, int target) {
                if(nums.empty())return {-1,-1};
        int n=nums.size();
        int l=0,r=n-1;
        vector<int>res;
        //left index of target
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                if(m==0||nums[m-1]<target){
                    res.push_back(m);
                    break;
                }else{
                    r=m-1;
                }
            }else if(nums[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        if(res.empty())return {-1,-1};
        // cout<<res[0]<<endl;
        int rl=res[0],rr=n-1;
        while(rl<=rr){
            int m=rl+(rr-rl)/2;
            if(nums[m]==target){
                if(m==n-1||nums[m+1]>target){
                    res.push_back(m);
                    break;
                }else{
                    rl=m+1;
                }
            }else if(nums[m]<target){
                rl=m+1;
            }else{
                rr=m-1;
            }
        }
        return {res[0],res[1]};
    }
};


class Solution2 {
public:
    int lower_bound(vector<int>&nums, int target){
        int n=nums.size();
        int l=0,r=n-1;

        //left index of target
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<target){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        int idx_1=lower_bound(nums, target);
        int idx_2=lower_bound(nums, target+1)-1;
        if(idx_1<nums.size()&&nums[idx_1]==target){
            return {idx_1,idx_2};
        }else{
            return {-1,-1};
        }
    }
};
