//
//  478_generate_random_point_in_a_circle.cpp
//  leetcode_math
//
//  Created by Hadley on 13.08.20.
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
    Solution(double radius, double x_center, double y_center) {
        h.push_back(x_center-radius);
        h.push_back(x_center+radius);
        v.push_back(y_center-radius);
        v.push_back(y_center+radius);
        this->radius=radius;
        this->x_center=x_center;
        this->y_center=y_center;
    }
    
    vector<double> randPoint() {
        float x,y;
        do{float random1=(float)rand()/(float)RAND_MAX;
        float diff_h=h[1]-h[0];
        x=diff_h*random1+h[0];
        
        float random2=(float)rand()/(float)RAND_MAX;
        float diff_v=v[1]-v[0];
        y=diff_v*random2+v[0];
        }while((x-x_center)*(x-x_center)+(y-y_center)*(y-y_center)>radius*radius);
        return {x,y};
    }
private:
    double radius;
    double x_center;
    double y_center;
    vector<int> h;
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
