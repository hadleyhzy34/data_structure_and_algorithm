//
//  455_assign_cookies.cpp
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0,cnt=0;
        for(int i=0;i<g.size();i++){
            if(j>=s.size())return cnt;
            if(s[j]>=g[i]){
                j++;
                cnt++;
            }else{
                j++;
                i--;
            }
        }
        return cnt;
    }
};
