//
//  594_longest_harmonious_subsequence.cpp
//  leetcode_hashtable
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
#include <map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        int lgst=0;
        for(auto x:map){
            if(map.find(x.first+1)!=map.end()){
                lgst=max(lgst,x.second+map[x.first+1]);
            }
        }
        return lgst;
    }
};
