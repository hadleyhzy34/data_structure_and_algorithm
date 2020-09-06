//
//  169_Majority_Element.cpp
//  leetcode_array
//
//  Created by Hadley on 18.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//hash map table to count frequency of each integer
class Solution169 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto num:nums){
            count[num]++;
            if(count[num]>nums.size()/2){
                return num;
            }
        }
        return 0;
    }
};


//using sort algorithm to make most majority number put in the middle of array
class Solution169_1 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

//using randomization
class Solution169_2 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        while(1){
            int index = rand()%nums.size();
            for(auto num:nums){
                if(num==nums[index]){
                    count++;
                }
                if(count>nums.size()/2){
                    return num;
                }
            }
            count = 0;
        }
    }
};

//usingbyer-moore voting algorithm
class Solution169_3 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int max_index = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[max_index]==nums[i]){
                count++;
            }else{
                count--;
            }
            if(count<=0){
                max_index = i;
                count=1;
            }
        }
        return nums[max_index];
    }
};


