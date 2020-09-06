//
//  367_perfect_square.cpp
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
    bool isPerfectSquare(int num) {
        long long l=0;
        long long r=num/2+1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(mid*mid<num){
                if((mid+1)*(mid+1)>num){
                    return false;
                }else if((mid+1)*(mid+1)<num){
                    l=mid+1;
                }else{
                    return true;
                }
            }else if(mid*mid>num){
                r=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};
