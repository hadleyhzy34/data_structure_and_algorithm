//
//  66_plus_one.cpp
//  leetcode_array
//
//  Created by Hadley on 17.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count = 0;
        digits[digits.size()-1]+=1;
        for(auto it = digits.rbegin();it!=digits.rend();it++){
            *it += count;
            count = 0;
            if(*it == 10){
                *it = 0;
                count++;
            }
        }
        if(count){digits.insert(digits.begin(), 1);}
        return digits;
    }
};
