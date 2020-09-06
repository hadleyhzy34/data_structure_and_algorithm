//
//  475_heaters.cpp
//  binary_search
//
//  Created by Hadley on 05.08.20.
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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = INT_MIN;
        sort(heaters.begin(),heaters.end());
        vector<int>::iterator it;
        for(int i: houses){
            it = lower_bound(heaters.begin(),heaters.end(),i);
            if(it == heaters.begin()) ans = max(ans,*it - i);
            else if(it == heaters.end()) ans = max(ans,i - *(it-1));
            else ans = max(ans, min(i - *(it-1), *it - i));
        }
        return ans;
    }
};
