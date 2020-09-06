//
//  75_sort_colors.cpp
//  leetcode_sort
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int count0=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
            }else if(nums[i]==1){
                count1++;
            }else{
                count2++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(count0){
                nums[i]=0;
                count0--;
            }else if(count1){
                nums[i]=1;
                count1--;
            }else{
                nums[i]=2;
                count2--;
            }
        }
    }
};


class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int count0=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
            }else if(nums[i]==1){
                count1++;
            }else{
                count2++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(count0){
                nums[i]=0;
                count0--;
            }else if(count1){
                nums[i]=1;
                count1--;
            }else{
                nums[i]=2;
                count2--;
            }
        }
    }
};
