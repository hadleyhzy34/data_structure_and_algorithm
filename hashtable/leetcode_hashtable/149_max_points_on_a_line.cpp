//
//  149_max_points_on_a_line.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 19.08.20.
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
    int maxPoints(vector<vector<int>>& points) {
        if(points.empty())return 0;
        if(points.size()==1)return 1;
        int maxPoint=0;
        for(int i=0;i<points.size()-1;i++){
            std::map<pair<double,double>,int> m;
            int count=0;
            for(int j=i+1;j<points.size();j++){
                if(points[i]==points[j]){
                    count++;continue;
                }
                if(points[j][0]==points[i][0]){
                    if(m.find(make_pair(points[i][0],numeric_limits<double>::infinity()))!=m.end()){
                        m[make_pair(points[i][0],numeric_limits<double>::infinity())]++;
                    }else{
                        m[make_pair(points[i][0],numeric_limits<double>::infinity())]+=2;
                    }
                    maxPoint=max(maxPoint,m[make_pair(points[i][0],numeric_limits<double>::infinity())]);
                }else{
                    double ratio=(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                    double b=(double)points[j][1]-ratio*(double)points[j][0];
                    if(m.find(make_pair(ratio, b))!=m.end()){
                        m[make_pair(ratio,b)]++;
                    }else{
                        m[make_pair(ratio,b)]+=2;
                    }
                    cout<<i<<" "<<j<<" "<<ratio<<" "<<b<<" "<<m[make_pair(ratio,b)]<<endl;
                    maxPoint=max(maxPoint,m[make_pair(ratio,b)]);
                }
            }
            if(count){
                if(m.empty()){
                   maxPoint=max(maxPoint,count+1);
                }else{
                    for(auto x:m){
                        x.second++;
                        maxPoint=max(maxPoint,x.second);
                    }
                }
            }
        }
        return maxPoint;
    }
};
