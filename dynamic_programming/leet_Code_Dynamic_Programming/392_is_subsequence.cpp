//
//  70_climbing_stairs.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 14.07.20.
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
    bool isSubsequence(string s, string t) {
        if(s.empty())return true;
            for(int j=0;j<t.size();j++){
                if(s[0]==t[j]){
                    if(s.size()==1){
                        return true;
                    }else{
                        return isSubsequence(s.substr(1),t.substr(j+1));
                    }
                }
            }
            return false;
        }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */







