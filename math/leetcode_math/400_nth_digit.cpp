//
//  400_nth_digit.cpp
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
    int findNthDigit(int n) {
        int count=1;
        string s;
        while(count<=n){
            s.append(to_string(count));
            if(s.length()>=n){
                return (char)(s[n-1]-'0');
            }else{
                count++;
            }
        }
        return 0;
    }
};
