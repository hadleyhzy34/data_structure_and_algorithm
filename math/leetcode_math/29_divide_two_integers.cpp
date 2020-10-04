//
//  29_divide_two_integers.cpp
//  leetcode_math
//
//  Created by Hadley on 13.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1)return dividend;
        if(dividend==INT_MIN&&divisor==-1)return INT_MAX;
        
        int sign=dividend>0^divisor>0?-1:1;
        
        long ans=0;
        long d=abs(dividend);
        long s=abs(divisor);
        
        int power=0;
        while(d>=s){
            int power=1;
            int temp_divisor=s;
            while(temp_divisor<<1<d){
                power<=1;
                temp_divisor<<=1;
            }
            ans+=power;
            d-=temp_divisor;
        }
        return sign*ans;
    }
};
