//
//  553_optimal_division.cpp
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
    string optimalDivision(vector<int>& nums) {
        auto n=nums.size();
        int L[n][n][2];
        memset(L, 0, sizeof(L));
        for(int i=0;i<nums.size();i++){
            L[i][i][0]=nums[i];
            L[i][i][1]=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            for(int l=1;i+l<nums.size();l++){
                L[i][i+l][0]=
            }
        }
    }
};
