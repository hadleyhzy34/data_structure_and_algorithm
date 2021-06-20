//
//  264_ugly_number_2.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 15.07.20.
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
    int nthUglyNumber(int n) {
        int ugly[n];
        memset(ugly, 0, sizeof(ugly));
        
        ugly[0]=1;
        int n2=2;
        int n3=3;
        int n5=5;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            ugly[i]=min(n2,min(n3,n5));
            if(ugly[i]==n2){
                i2=i2+1;
                n2=ugly[i2]*2;
            }
            if(ugly[i]==n3){
                i3=i3+1;
                n3=ugly[i3]*3;
            }
            if(ugly[i]==n5){
                i5=i5+1;
                n5=ugly[i5]*5;
            }
        }
        return ugly[n-1];
    }
};
