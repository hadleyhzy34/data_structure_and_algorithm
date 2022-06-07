//
//  487_max_consecutive_ones_2.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 15.08.20.
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ptr1=0;
        int l1=0,l2=0;
        int res=0;
        int i=0;
        auto n=nums.size();
        while(i<n){
            if(nums[i]==1){
                i++;
                l1++;
                l2++;
            }else{
                if(ptr1==0){
                    i++;
                    l1++;
                    ptr1=1;
                    res=max(res,l2);
                    l2=0;
                }else{
                    res=max(res,l1);
                    i++;
                    ptr1=0;
                    l1=0;
                    l2++;
                }
            }
            // cout<<i<<" "<<l1<<" "<<l2<<endl;
        }
        res=max(res,max(l1,l2));
        return res;
    }
};
