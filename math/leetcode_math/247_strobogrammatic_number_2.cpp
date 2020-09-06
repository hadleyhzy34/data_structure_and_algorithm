//
//  247_strobogrammatic_number_2.cpp
//  leetcode_math
//
//  Created by Hadley on 12.08.20.
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
    vector<string> findStrobogrammatic(int n) {
        vector<vector<string>>res(n+1);
        if(n==1)return {"0","1","8"};
        if(n==2)return {"11","69","88","96"};
        res[1]={"0","1","8"};
        res[2]={"00","11","69","88","96"};
        
        for(int i=(n&1)?3:4;i<=n;i+=2){
            for(int j=0;j<res[i-2].size();j++){
                res[i].push_back("1"+res[i-2][j]+"1");
                res[i].push_back("8"+res[i-2][j]+"8");
                res[i].push_back("6"+res[i-2][j]+"9");
                res[i].push_back("9"+res[i-2][j]+"6");
                if(i<n)res[i].push_back("0"+res[i-2][j]+"0");
                // cout<<i<<" "<<j<<" "<<res[i-2][j]<<endl;
            }
        }
        return res[n];
    }
};

class Solution2 {
public:
    vector<string> findString(int n,int m){
        if(n==1)return {"0","1","8"};
        if(n==2)return {"00","11","69","88","96"};
        vector<string> res;
        vector<string> r=findString(n-2,m);
        for(int i=0;i<r.size();i++){
            res.push_back("1"+r[i]+"1");
            res.push_back("8"+r[i]+"8");
            res.push_back("6"+r[i]+"9");
            res.push_back("9"+r[i]+"6");
            if(n<m)res.push_back("0"+r[i]+"0");
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        if(n==1)return {"0","1","8"};
        if(n==2)return {"11","69","88","96"};
        return findString(n, n);
    }};
