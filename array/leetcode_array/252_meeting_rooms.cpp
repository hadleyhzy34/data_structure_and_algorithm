//
//  252_meeting_rooms.cpp
//  leetcode_array
//
//  Created by Hadley on 27.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        auto temp=intervals;
        
        sort(temp.begin(),temp.end(),[](auto const &a,auto const &b)
        {
            return a[1]<b[1];
            
        });
        
        for(int i=1;i<temp.size();i++){
            if(temp[i][0]<temp[i-1][1]){
                return false;
            }
        }
        return true;
    }
};
