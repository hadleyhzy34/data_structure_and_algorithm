//
//  246_strobogrammatic_number.cpp
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
    bool isStrobogrammatic(string num) {
        auto n=num.length();
        string temp=num;
        unordered_map<char, char>r;
        r['6']='9';
        r['9']='6';
        r['8']='8';
        r['1']='1';
        r['0']='0';
        r['2']='*';
        r['3']='*';
        r['4']='*';
        r['5']='*';
        r['7']='*';
        
        for(int i=0;i<n;i++){
            temp[i]=r[temp[i]];
        }
        reverse(temp.begin(), temp.end());
        return temp==num;
    }
};
