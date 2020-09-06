//
//  252_meeting_rooms.cpp
//  leetcode_sort
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution252 {
public:
    bool couldAttend(vector<pair<int,int>> times) {
        sort(times.begin(),times.end());
        vector<pair<int,int>> t;
        sort(t.begin(),t.end(),[](pair<int,int>a,pair<int,int>b){return a.second>b.second;});
        if(times==t){
            return true;
        }else{
            return false;
        }
    }
};
