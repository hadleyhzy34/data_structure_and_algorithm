//
//  259_3sum_smaller.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 15.08.20.
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
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        auto n=nums.size();
        int res=0;
        for(int i=0;i+2<nums.size();i++){
            int l=i+1,r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]<target){
                    res+=r-l;
                    l++;
                }else{
                    r--;
                }
            }
        }
        return res;
    }
};
