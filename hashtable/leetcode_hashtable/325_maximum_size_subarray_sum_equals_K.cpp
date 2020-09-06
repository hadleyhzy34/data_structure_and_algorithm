//
//  325_maximum_size_subarray_sum_equals_K.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 19.08.20.
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
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum=0,l=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                cout<<i<<endl;
                l=max(l,i+1);
            }else{
                if(m.find(sum-k)!=m.end()){
                    cout<<i<<" "<<m[sum-k]<<" "<<endl;
                    l=max(l,i-m[sum-k]);
                }
            }
            if(m.find(sum)==m.end())m[sum]=i;
        }
        return l;
    }
};
