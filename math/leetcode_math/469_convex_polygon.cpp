//
//  469_convex_polygon.cpp
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
    int check(vector<int> point, vector<int> p1,vector<int>p2){
        if(p1[0]==p2[0]){
            if(point[0]==p1[0]){
                return 0;
            }else if (point[0]>p1[0]){
                return 1;
            }else{
                return 2;
            }
        }
        // cout<<point[0]<<" "<<point[1]<<" "<<point[0]*(double)(p2[1]-p1[1])/(double)(p2[0]-p1[0])<<" "<<(double)(p2[0]*p1[1]-p1[0]*p2[1])/(double)(p2[0]-p1[0])<<endl;
            double yc=point[0]*(double)(p2[1]-p1[1])/(double)(p2[0]-p1[0])+(double)(p2[0]*p1[1]-p1[0]*p2[1])/(double)(p2[0]-p1[0]);
            if(point[1]==yc){
                return 0;
            }else if(point[1]>yc){
                return 1;
            }else{
                return 2;
            }
    }
        
    bool isConvex(vector<vector<int>>& points) {
        auto n=points.size();
        if(n==3)return true;
        for(int i=0;i<points.size();i++){
            if(check(points[i], points[(n+i-1)%n], points[(n+i+1)%n])==0)continue;
            for(int j=i+2;j<i+n-2;j++){
                if(check(points[i], points[(n+i-1)%n], points[(n+i+1)%n])==check(points[(n+j)%n], points[(n+i-1)%n], points[(n+i+1)%n])){
                    return false;
                }
            }
        }
        return true;
    }
};
