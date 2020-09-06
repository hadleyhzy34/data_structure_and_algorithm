//
//  34_find_first_and_last_position_of_element_in_sorted_array.cpp
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
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        auto n=nums.size();
        
        int start=-1,end=-1;
        
        //search left most position of a given target
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                if(m==0||nums[m-1]!=target){
                    start=m;
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
        if(start==-1)return{-1,-1};
        
        //search right most position of a given target
        int ll=0,rr=n-1;
        while(ll<=rr){
            int m=ll+(rr-ll)/2;
            if(nums[m]==target){
                if(m==n-1||nums[m+1]!=target){
                    end=m;
                    break;
                }else{
                    ll=m+1;
                }
            }else if(nums[m]<target){
                ll=m+1;
            }else{
                rr=m-1;
            }
        }
        return {start,end};
    }
};
