//
//  474_ones_and_zeros.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 21.07.20.
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
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> cal;
        for(auto it:strs){
            auto zero=std::count(it.begin(),it.end(),'0');
            auto one=it.size()-zero;
            cal.push_back(make_pair(zero,one));
        }
        auto size=strs.size();
        int c[size+1][m+1][n+1];
        memset(c, 0, sizeof(c));

        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int l=1;l<=size;l++){
                    auto zeros=cal[l-1].first;
                    auto ones=cal[l-1].second;
                    if(i>=zeros&&j>=ones){
                        c[l][i][j]=max(c[l-1][i][j],c[l-1][i-zeros][j-ones]+1);
                    }else{
                        c[l][i][j]=c[l-1][i][j];
                    }
                }
            }
        }
        
        return c[size][m][n];
    }
};
