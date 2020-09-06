//
//  16_3sum_closest.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 14.08.20.
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
    int threeSumClosest(vector<int>& nums, int target) {
        auto n=nums.size();
        int res=INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int l=i+1,r=n-1;
            while(l<r){
                if(abs(res)>abs(nums[i]+nums[l]+nums[r]-target)){
                    res=nums[i]+nums[l]+nums[r]-target;
                }
                if(nums[i]+nums[l]+nums[r]-target>0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return res+target;
    }
};
