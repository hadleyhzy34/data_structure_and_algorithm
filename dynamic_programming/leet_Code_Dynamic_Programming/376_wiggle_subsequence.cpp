//
//  376_wiggle_subsequence.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 20.07.20.
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
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())return 0;
        auto n=nums.size();
        //L[i].first represent that last difference is positive, L[i].second represent that last difference is negative
        vector<pair<int, int>> L(nums.size(),make_pair(1, 1));
        int max_length=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]&&L[i].first<(L[j].second+1)){
                    L[i].first=L[j].second+1;
                }
                if(nums[j]>nums[i]&&L[i].second<(L[j].first+1)){
                    L[i].second=L[j].first+1;
                }
            }
            max_length=max(max_length,max(L[i].first,L[i].second));
        }
        return max_length;
    }
};
