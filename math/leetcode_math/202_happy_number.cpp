//
//  202_happy_number.cpp
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
    bool isHappy(int n) {
        unordered_map<int, int>c;
        int temp=n;
        int res=0;
        do{
            res=0;
            while(temp!=0){
                res+=temp%10*temp%10;
                temp=temp/10;
            }
            temp=res;
            if(res==1)return true;
        }while (c.find(res)==c.end());
        return false;
    }
};
