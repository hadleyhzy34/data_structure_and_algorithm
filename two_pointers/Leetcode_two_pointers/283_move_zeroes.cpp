//
//  283_move_zeroes.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 27.09.20.
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
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[cnt++]=nums[i];
            }
        }
        for(int i=cnt;i<nums.size();i++){
            nums[i]=0;
        }
    }
};
