//
//  575_distribute_candies.cpp
//  leetcode_array
//
//  Created by Hadley on 01.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class solution{
public:
    int distributeCandies(vector<int>& candies) {
        return min(unordered_set<int>(candies.begin(),candies.end()).size(), candies.size()/2);
    }
};

class solution2{
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int,int>map;
        int cnt=0;
        for(auto&x:candies){
            if(map.find(x)==map.end()){
                cnt++;
            }
            map[x]++;
        }
        
        if(cnt>=candies.size()/2){
            return candies.size()/2;
        }else{
            return cnt;
        }
    }
};
