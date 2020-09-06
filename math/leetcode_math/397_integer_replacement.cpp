//
//  397_integer_replacement.cpp
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
    int integerReplacement(int n) {
        if(n==2)return 1;
        if(n==1)return 0;
        if(!(n&(n-1)))return log2(n)+1;
        if(n&1){
            if(n==INT_MAX){
                return integerReplacement(n-1)+1;
            }else{
                return min(integerReplacement(n+1),integerReplacement(n-1))+1;
            }
        }else{
            return integerReplacement(n/2)+1;
        }
    }
};
