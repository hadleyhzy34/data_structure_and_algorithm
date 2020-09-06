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
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty())return 0;
        if(costs.size()==1)return *min_element(costs[0].begin(), costs[0].end());
        vector<vector<int>>price(costs.size(),{0,0,0});
        price[0][0]=costs[0][0];
        price[0][1]=costs[0][1];
        price[0][2]=costs[0][2];
        for(int i=1;i<costs.size();i++){
            //each represent minmimum price when choosing certain color at current house
            price[i][0]=min(price[i-1][1],price[i-1][2])+costs[i][0];
            price[i][1]=min(price[i-1][0],price[i-1][2])+costs[i][1];
            price[i][2]=min(price[i-1][0],price[i-1][1])+costs[i][2];
        }
        return *min_element(price[price.size()-1].begin(), price[price.size()-1].end());
    }
};





