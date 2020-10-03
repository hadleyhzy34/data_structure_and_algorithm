//
//  504_base_7.cpp
//  leetcode_math
//
//  Created by Hadley on 29.09.20.
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
    string convertToBase7(int num) {
        string res;
        int t=abs(num);
        
        while(t){
            res=to_string(t%7)+res;
            t/=7;
        }
        if(num>=0){
            return res;
        }else{
            return "-1"+res;
        }
    }
};
