//
//  377_combination_sum_4.cpp
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
    int combinationSum4(vector<int>& nums, int target) {
        int L[target+1];
        memset(L, 0, sizeof(L));
        
        for(int i=1;i<=target;i++){
            for(int j=1;j<i;j++){
                if(j==(i-j)){
                    L[i]+=L[j];
                }else{
                    L[i]+=L[j]*L[i-j];
                }
            }
            if(find(nums.begin(), nums.end(), i)!=nums.end())L[i]++;
        }
        return L[target];
    }
};

class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> L(target+1,0);
        L[0]=1;
        
        
        for(int i=0;i<=target;i++){
            for(auto j:nums){
                if(i+j>target)continue;
                L[i+j]+=L[i];
            }
        }
        return L[target];
    }
};


class Solution3 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> L(target+1,0);
        L[0]=1;
        
        
        for(int i=0;i<=target;i++){
            for(auto j:nums){
                if(i<j)continue;
                L[i]+=L[i-j];
            }
        }
        return L[target];
    }
};
