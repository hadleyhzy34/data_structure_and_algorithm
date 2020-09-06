//
//  448_find_all_numbers_disappeared_in_an_array.cpp
//  leetcode_array
//
//  Created by Hadley on 20.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int>count;
        vector<int> fdNumber;
        for(auto num:nums){
            count[num]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(!count.count(i)){
                fdNumber.push_back(i);
            }
        }
        return fdNumber;
    }
};

class Solution448_2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int x= nums[i];
            nums[abs(x)-1]=-abs(nums[abs(x)-1]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};


