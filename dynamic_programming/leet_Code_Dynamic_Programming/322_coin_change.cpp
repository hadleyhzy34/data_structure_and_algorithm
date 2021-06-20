//
//  322_coin_change.cpp
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
    int coinChange(vector<int>& coins, int amount) {
        if(!amount)return 0;
        int lAmount[amount+1];
        memset(lAmount, -1, sizeof(lAmount));
        
        for(int i=1;i<=amount;i++){
            if(find(coins.begin(), coins.end(), i)!=coins.end()){
                lAmount[i]=1;
            }else{
                for(int j=0;j<coins.size();j++){
                    if(i<coins[j])continue;
                    int temp_min=1+lAmount[i-coins[j]];
                    if(lAmount[i]==-1){
                        if(temp_min!=0){
                            lAmount[i]=temp_min;
                        }
                    }else{
                        if(temp_min!=0&&temp_min<lAmount[i])lAmount[i]=temp_min;
                    }
                }
            }
        }
        return lAmount[amount+1];
    }
};
