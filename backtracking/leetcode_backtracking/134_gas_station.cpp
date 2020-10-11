//
//  134_gas_station.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 06.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            //starting station
            if(gas[i]<cost[i])continue;
            int j=(i+1)%gas.size();
            int r=gas[i]-cost[i];
            while(j!=i){
                r+=gas[j]-cost[j];
                // cout<<i<<" "<<j<<" "<<r<<endl;
                if(r<0)break;
                j=(j+1)%gas.size();
            }
            if(r>=0)return i;
        }
        return -1;
    }
};

class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            //starting station
            if(gas[i]<cost[i])continue;
            int j=(i+1)%gas.size();
            int r=gas[i]-cost[i];
            while(j!=i){
                r+=gas[j]-cost[j];
                // cout<<i<<" "<<j<<" "<<r<<endl;
                if(r<0)break;
                j=(j+1)%gas.size();
            }
            if(r>=0)return i;
        }
        return -1;
    }
};
