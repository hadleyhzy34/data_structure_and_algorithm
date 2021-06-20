//
//  279_perfect_squares.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 17.07.20.
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
    int numSquares(int n) {
        int lNumber[n+1];
        memset(lNumber, 0, sizeof(lNumber));

        for(int i=1;i<=n;i++){
            if((sqrt(i)-floor(sqrt(i)))==0){
                lNumber[i]=1;
            }else{
                for(int j=1;(j*j)<i;j++){
                    int count=1+lNumber[i-(j*j)];
                    if(lNumber[i]==0||count<lNumber[i])lNumber[i]=count;
                }
            }
        }
        return lNumber[n];
    }
};
