//
//  309_best_time_to_buy_and_sell_stock_with_cooldown.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 20.07.20.
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
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)return 0;
        auto n=prices.size();
        int L[n][2];
        memset(L, 0, sizeof(L));
        
        //buy stock at 0th element
        L[0][0]=-prices[0];
        //sell stock at 0th element
        L[0][1]=0;
        //buy stock at 1th element, it could be stock we bought at 0th element and we rest at 1th element or we bought at 1th element
        L[1][0]=max(L[0][0],-prices[1]);
        //sell stock at 1th element
        L[1][1]=max(0,prices[1]-prices[0]);
        
        for(int i=2;i<n;i++){
            L[i][0]=max(L[i-1][0],L[i-2][1]-prices[i]);
            L[i][1]=max(L[i-1][1],L[i-1][0]+prices[i]);
        }
        return L[n-1][1];
    }
};
