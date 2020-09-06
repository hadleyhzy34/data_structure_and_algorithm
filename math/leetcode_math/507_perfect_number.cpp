//
//  507_perfect_number.cpp
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
    bool checkPerfectNumber(int num) {
        if(num<=0)return false;
        int res=0;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                res+=i;
                if(i*i!=num){
                    res+=num/i;
                }
            }
            cout<<i<<" "<<res<<endl;
        }
        return res-num==num;
    }
};
