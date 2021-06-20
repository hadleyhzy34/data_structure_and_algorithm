//
//  357_count_numbers_with_unique_digits.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 22.07.20.
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
    int countNumbersWithUniqueDigits(int n) {
        if(!n)return 1;
        
        int sum=10;
        int curUniDig=9;
        for(int i=2;i<=n;i++){
            curUniDig*=(10-(i-1));
            sum+=curUniDig;
        }
        return sum;
    }
};
