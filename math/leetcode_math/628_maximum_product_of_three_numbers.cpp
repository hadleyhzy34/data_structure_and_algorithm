//
//  628_maximum_product_of_three_numbers.cpp
//  leetcode_math
//
//  Created by Hadley on 11.08.20.
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
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto n=nums.size();
        int maxProduct=nums[n-1]*nums[n-2]*nums[n-3];
        return max(maxProduct,nums[0]*nums[1]*nums[n-1]);
    }
};
