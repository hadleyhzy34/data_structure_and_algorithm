//
//  414_third_maximum_number.cpp
//  leetcode_array
//
//  Created by Hadley on 20.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution414 {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()<3){return *max_element(nums.begin(), nums.end());}
        vector<int> max;
        for(auto num:nums){
            cout<<num<<endl;
            if(max.empty()){
                max.push_back(num);
                continue;
            }
            switch (max.size()) {
                case 1:
                    if(num>max[0]){
                        max.push_back(max[0]);
                        max[0] = num;
                    }
                    if(num<max[0]){
                        max.push_back(num);
                    }
                    break;
                case 2:
                    if(num>max[0]){
                        max.push_back(max[1]);
                        max[1] = max[0];
                        max[0] = num;
                    }else if(max[1]<num&&num<max[0]){
                        max.push_back(max[1]);
                        max[1] = num;
                    }else if(num<max[1]){
                        max.push_back(num);
                    }
                    break;
                case 3:
                    if(num>max[0]){
                        max[2] = max[1];
                        max[1] = max[0];
                        max[0] = num;
                    }else if(max[1]<num&&num<max[0]){
                        max[2] = max[1];
                        max[1] = num;
                    }else if(max[2]<num&&num<max[1]){
                        max[2] = num;
                    }
                    break;
                default:
                    break;
            }
        }
        if(max.size()<3){
            return max[0];
        }else{
            return max[2];
        }
    }
};


//using minimum integer number of limits solution2

//
