//
//  346_moving_average_from_data_stream.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 27.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include "83_Remove_duplicats_from_sorted_list.cpp"
using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size=size;
    }
    
    double next(int val) {
        if(q.size()<size){
            q.push(val);
            sum=sum+val;
            return sum/q.size();
        }else{
            q.push(val);
            sum=sum+val-q.front();
            q.pop();
            return sum/q.size();
        }
    }
private:
    queue<int> q;
    int size;
    double sum=0.0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
