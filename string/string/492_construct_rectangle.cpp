//
//  500_keyboard_row.cpp
//  string
//
//  Created by Hadley on 29.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> constructRectangle(int area) {
        int maxLength=0;
        int w=1;
        for(int i=1;i<=area/2;i++){
            if(area%i==0){
                if(abs(i-area/i)<maxLength){
                    maxLength=abs(i-area/i);
                    w=i;
                }
            }
        }
        return {area/w,w};
    }
};
