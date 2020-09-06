//
//  525_contiguous_array.cpp
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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>m1;
        int res=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum+=-1;
            }else{
                sum++;
            }
            if(m1.find(sum)!=m1.end()){
                res=max(res,i-m1[sum]);
            }
            if(sum==0){
                res=max(res,i+1);
            }
            if(m1.find(sum)==m1.end()){
                m1[sum]=i;
            }
        }
        return res;
    }
};
