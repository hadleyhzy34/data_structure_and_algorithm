//
//  356_line_reflection.cpp
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
#include <map>
using namespace std;

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
//        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
//            if(a[0]<b[0]){
//                return true;
//            }else if(a[0]==b[0]){
//                return a[1]<b[1];
//            }else{
//                return false;
//            }
//        });
//        for(int i=1;i<points.size();i++){
//            if(points[i][0]==points[i-1][0]&&points[i][1]==points[i-1][1]){
//                points.erase(points.begin()+i);
//                i--;
//            }
//        }
        
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]<b[0]){
                return true;
            }else if(a[0]==b[0]){
                return a[1]<b[1];
            }else{
                return false;
            }
        });
        for(int i=1;i<points.size();i++){
            if(points[i][0]==points[i-1][0]&&points[i][1]==points[i-1][1]){
                points.erase(points.begin()+i);
                i--;
            }
        }
        auto n=points.size();
        sort(points.begin()+n/2,points.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]<b[0]){
                return true;
            }else if(a[0]==b[0]){
                return a[1]>b[1];
            }else{
                return false;
            }
        });
        double mid=points[0][0]+(double)(points[n-1][0]-points[0][0])/2;
        cout<<mid<<endl;
        for(int i=0;i<=n/2;i++){
            if(n&1&&i==n/2){
                if(mid==points[i][0]){
                    continue;
                }else{
                    return false;
                }
            }
            if((mid==points[i][0]&&mid==points[n-1-i][0])||(mid-points[i][0]==points[n-1-i][0]-mid&&points[i][1]==points[n-1-i][1])){
                continue;
            }else{
                // cout<<mid<<" "<<points[i][0]<<" "<<points[n-1-i][0]<<" "<<points[i][1]<<endl;
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isReflected(vector<vector<int>>& points) {
        map<pair<int, int>,int>h;
        int l=points[0][0];
        int r=points[0][0];
        for(auto x:points){
            h[make_pair(x[0], x[1])]++;
            l=min(l,x[0]);
            r=max(r,x[0]);
        }
        double mid=l+(double)(r-l)/2;
        auto n=points.size();
        
        // cout<<mid<<endl;
        for(int i=0;i<n;i++){
            int x=(points[i][0]>mid)?mid-(points[i][0]-mid):mid+(mid-points[i][0]);
            // cout<<points[i][0]<<" "<<x<<endl;
            if(x!=mid&&h.find(make_pair(x, points[i][1]))==h.end())return false;
        }
        return true;
    }
};
