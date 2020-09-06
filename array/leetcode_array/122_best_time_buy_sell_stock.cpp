//
//  122_best_time_buy_sell_stock.cpp
//  leetcode_array
//
//  Created by Hadley on 17.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            while(prices[i]>prices[i-1]){
                profit += (prices[i]-prices[i-1]);
                i++;
                if(i==prices.size())break;
            }
        }
        return profit;
    }
};
