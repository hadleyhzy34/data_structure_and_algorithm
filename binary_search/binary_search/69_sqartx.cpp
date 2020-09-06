//
//  69_sqartx.cpp
//  binary_search
//
//  Created by Hadley on 05.08.20.
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
    int mySqrt(int x) {
        if(x==0)return 0;
        for(int i=0;i<=x;i++){
            if(i*i>x)return i-1;
        }
        return 0;
    }
};

class Solution1 {
public:
    int mySqrt(int x) {
        long long l=0;
        long long r=x/2+1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(mid*mid<=x){
                if((mid+1)*(mid+1)>x){
                    return mid;
                }else{
                    l=mid+1;
                }
            }else{
                r=mid-1;
            }
        }
        return 0;
    }
};
