//
//  121_best_time_buy_and_sell_stock.cpp
//  leetcode_array
//
//  Created by Hadley on 17.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                profit = max(profit, prices[j]-prices[i]);
            }
        }
        if(profit<0){return 0;}
        return profit;
    }
};

class Solution121_1 {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()){return 0;}
        int min_price = prices[0];
        int max_price = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_price){
                min_price = prices[i];
            }else if ((prices[i]-min_price)>max_price){
                max_price = prices[i]-min_price;
            }
        }
        if(max_price<0){return 0;}
        return max_price;
    }
};
