//
//  346_moving_average_from_data_stream.cpp
//  leetCode_queue
//
//  Created by Hadley on 06.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

class MovingAverage{
  public:
    MovingAverage(int size){
        windowSize=size;
    }
    double next(int input){
        if(q.size()>=windowSize){
            sum-=q.front();
            q.pop();
        }
            sum+=input;
            q.push(input);
            return sum/q.size();
    }
private:
    int windowSize;
    int sum;
    queue<int> q;
};
