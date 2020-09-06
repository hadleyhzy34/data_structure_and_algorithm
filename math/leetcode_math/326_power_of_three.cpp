//
//  326_power_of_three.cpp
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
    bool isPowerOfThree(int n) {
        int maxThree=pow(3,int(log10(INT_MAX)/log10(3)));
        // cout<<INT_MAX<<" "<<log10(INT_MAX)/log10(3)<<" "<<maxThree<<endl;
        return n>0&&maxThree%n==0;
    }
};
