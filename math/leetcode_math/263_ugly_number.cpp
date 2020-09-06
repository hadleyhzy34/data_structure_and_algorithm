//
//  263_ugly_number.cpp
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
    bool isUgly(int num) {
        if(num<1)return false;
        int temp=num;
        while(temp!=1){
            if(temp%2==0||temp%3==0||temp%5==0){
                if(temp%2==0){
                    temp=temp/2;
                }else if(temp%3==0){
                    temp=temp/3;
                }else{
                    temp=temp/5;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};
