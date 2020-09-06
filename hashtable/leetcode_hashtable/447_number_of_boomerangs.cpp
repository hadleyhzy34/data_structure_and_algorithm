//
//  447_number_of_boomerangs.cpp
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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        //m.first.first: index of first point m.first.second:distance to this point m.second: points that have m.first.second distance to first point
        map<pair<int,int>,int>m;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                int distance=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                m[make_pair(i, distance)]++;
            }
        }
        int res=0;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>=2){
                res+=it->second*(it->second-1);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        //m.first.first: index of first point m.first.second:distance to this point m.second: points that have m.first.second distance to first point
        int res=0;
        for(int i=0;i<points.size();i++){
            unordered_map<int, int>map;
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                int distance=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                map[distance]++;
            }
            for(auto x:map){
                if(x.second>=2){
                    res+=x.second*(x.second-1);
                }
            }
        }
        
        return res;
    }
};

