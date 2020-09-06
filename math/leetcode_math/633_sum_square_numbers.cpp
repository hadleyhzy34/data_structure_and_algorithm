//
//  633_sum_square_numbers.cpp
//  leetcode_math
//
//  Created by Hadley on 11.08.20.
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
    bool judgeSquareSum(int c) {
        for(long i=0;i*i<=c;i++){
            double b=sqrt(c-long(i*i));
            if(b==(int)b)return true;
        }
        return false;
    }
};
