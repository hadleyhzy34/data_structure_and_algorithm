//
//  70_climbing_stairs.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 14.07.20.
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
    int numWays(int n, int k) {
        if(!n||!k)return 0;
        if(n==1)return k;
        int count[n+1];
        count[1]=k;
        count[2]=k*k;
        for(int i=3;i<=n;i++){
            count[i]=count[i-1]*(k-1)+count[i-2]*(k-1);
        }
        return count[n];
    }
};






