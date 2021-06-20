//
//  279_perfect_squares.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 17.07.20.
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
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())return 0;
        auto n=nums.size();
        vector<int> L(nums.size(),1);
        int max_length=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]&&L[i]<(L[j]+1)){
                    L[i]= L[j]+1;
                }
            }
            max_length=max(max_length,L[i]);
        }
        return max_length;
    }
};

