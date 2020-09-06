//
//  497_random_point_in_non_over_lapping_rectangles.cpp
//  binary_search
//
//  Created by Hadley on 11.08.20.
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
    Solution(vector<vector<int>>& rects) {
            n=rects.size();
            this->rects=rects;
            for(int i=0;i<n;i++){
                area+=(rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
                b.push_back(area);
            }
        }
        
        vector<int> pick() {
            int h=rand()%area+1;
            int l=0,r=n-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(b[m]>=h){
                    if(m==0||b[m-1]<h){
                        int x=rand()%(rects[m][2]-rects[m][0]+1)+rects[m][0];
                        int y=rand()%(rects[m][3]-rects[m][1]+1)+rects[m][1];
                        return {x,y};
                    }else{
                        r=m-1;
                        }
                }else{
                        l=m+1;
                }
            }
            return {0,0};
        }
    private:
        int area=0;
        vector<vector<int>> rects;
        vector<int> b;
        int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
