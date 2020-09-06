//
//  598_range_addition_2.cpp
//  leetcode_math
//
//  Created by Hadley on 12.08.20.
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
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minV=m;
        int minH=n;
        for(int i=0;i<ops.size();i++){
            minV=min(minV,ops[i][0]);
            minH=min(minH,ops[i][1]);
        }
        return minV*minH;
    }
};
