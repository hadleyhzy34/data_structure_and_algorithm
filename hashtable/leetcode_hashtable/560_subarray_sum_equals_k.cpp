//
//  560_subarray_sum_equals_k.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 20.08.20.
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
#include <map>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>m1;
        int res=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(m1.find(sum-k)!=m1.end()){
                res+=m1[sum-k];
            }
            m1[sum]++;
        }
        return m1[k]+res;
    }
};
