//
//  31_next_permutaion.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                int count=i;
                int t=nums[i];
                for(int j=nums.size()-1;j>i;j--){
                    if(nums[j]>nums[i-1]&&nums[j]<t){
                        t=nums[j];
                        count=j;
                    }
                }
                swap(nums[count],nums[i-1]);
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};
