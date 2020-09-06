//
//  462_minimum_moves_to_equal_array_elements_2.cpp
//  leetcode_math
//
//  Created by Hadley on 13.08.20.
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
    int minMoves2(vector<int>& nums) {
        int l=0,r=nums.size()-1,sum=0;
        sort(nums.begin(),nums.end());
        while(l<r){
            sum+=nums[r]-nums[l];
            l++;
            r--;
        }
        return sum;
    }
};
