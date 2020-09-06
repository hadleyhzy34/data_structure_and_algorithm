//
//  7_reverse_integer.cpp
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
    int reverse(int x) {
        int output=0;
        while(x!=0){
            if(output<=INT_MAX/10&&output>=INT_MIN/10){
                output=output*10+x%10;
                x=x/10;
            }else{
                return 0;
            }
        }
        return output;
    }
};
