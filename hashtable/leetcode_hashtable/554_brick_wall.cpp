//
//  554_brick_wall.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 20.08.20.
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
#include <map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int>map;
        int maxFre=0;
        for(int i=0;i<wall.size();i++){
            int count=0;
            for(int j=0;j<wall[i].size()-1;j++){
                count+=wall[i][j];
                maxFre=max(maxFre,++map[count]);
            }
        }
        return wall.size()-maxFre;
    }
};
