//
//  405_convert_a_number_to_hexidecimal.cpp
//  leetcode_math
//
//  Created by Hadley on 01.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    string hex="0123456789abcdef";
    string toHex(int num) {
        //bit shift negative number could cause undefined behaviour
        //be careful that numbers num in binary form is the same as n in binary form while numbers in decimal is not the same as n in decimal form out of range 0~2^31
        //which means the unsigned number binary form of 2^31+1 is the same as binary form of signed number -2^31-1
        unsigned n=num;
        // int n=num;
        if(n==0)return "0";
        string res;
        while(n){
            res=hex[0xf&n]+res;
            n=n>>=4;
            cout<<n<<" "<<res<<endl;
        }
        return res;
    }
};
