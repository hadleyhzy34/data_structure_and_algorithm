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
    Solution():count(45,0){};
    
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        if(count[n]!=0)return count[n];
        count[n]=climbStairs(n-1)+climbStairs(n-2);
        return count[n];
    }
    
private:
    vector<int>count;
};

class Solution2 {
public:
    int climbStairs(int n) {
        int count[46];
        count[1]=1;
        count[2]=2;
        for(int i=3;i<=n;i++){
            count[i]=count[i-1]+count[i-2];
        }
        return count[n];
    }
};
