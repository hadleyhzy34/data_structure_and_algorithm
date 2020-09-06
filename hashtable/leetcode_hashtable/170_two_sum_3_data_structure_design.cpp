//
//  170_two_sum_3_data_structure_design.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 15.08.20.
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


class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        map[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto &x:map){
            // cout<<x.first<<endl;
            if(map.find(value-x.first)!=map.end()){
                if(map.find(value-x.first)!=map.find(x.first)||map[x.first]>=2)return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int>map;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
