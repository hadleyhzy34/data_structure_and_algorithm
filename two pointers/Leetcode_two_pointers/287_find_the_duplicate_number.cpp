//
//  287_find_the_duplicate_number.cpp
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
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int>r;
        for(int i=0;i<nums.size();i++){
            if(r.find(nums[i])==r.end()){
                r[nums[i]]++;
            }else{
                return nums[i];
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int>r;
        for(int i=0;i<nums.size();i++){
            if(r.find(nums[i])==r.end()){
                r[nums[i]]++;
            }else{
                return nums[i];
            }
        }
        return 0;
    }
};
