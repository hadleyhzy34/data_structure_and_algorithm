//
//  70_climbing_stairs.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 14.07.20.
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


class NumArray {
public:
    NumArray(vector<int>& nums):sum(nums.size(),0) {
        if(!nums.empty()){
            sum[0]=nums[0];
            for(int i=1;i<nums.size();i++){
                sum[i]=sum[i-1]+nums[i];
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(sum.size()==0)return 0;
        if(i>=1)
            return sum[j]-sum[i-1];
        return sum[j];
    }
private:
    vector<int>sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */







