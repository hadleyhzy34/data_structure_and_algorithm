//
//  41_first_missing_positive.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 29.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

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
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto &x:nums){
            map[x]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(map.find(i)==map.end()){
                return i;
            }
        }
        return nums.size()+1;
    }
};
