//
//  475_heaters.cpp
//  leetcode_array
//
//  Created by Hadley on 01.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int res=0;
        for(int i=0;i<houses.size();i++){
            auto r=lower_bound(heaters.begin(), heaters.end(), houses[i]);
            int radius=INT_MAX;
            if(r!=heaters.end()){
                radius=*r-houses[i];
            }
            if(r!=heaters.begin()){
                auto l=r-1;
                radius=min(radius,houses[i]-*l);
            }
            res=max(res,radius);
        }
        return res;
    }
};
