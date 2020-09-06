//
//  172_factorial_trailing_zeroes.cpp
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
    int trailingZeroes(int n) {
//1*2*3*4*5*......25*26*27*28*29*30*31
//        5-10-15-20-25-30
//        1*5-2*5-3*5-4*5-5*5-6*5
//        1-1-1-1-2-1
//        if(n/5>=5) res=n/5+n/25
//        if(n/25>=5) res=n/5+n/25+n/125
            
        long res=0;
        long temp=n;;
        while(temp>=5){
            temp=temp/5;
            res+=temp;
        }
        return res;
    }
};
