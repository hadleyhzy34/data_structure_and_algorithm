//
//  599_minimum_index_sum_of_two_lists.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 20.08.20.
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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int leastSum=list1.size()+list2.size()-2;
        vector<string> res;
        unordered_map<string, int>l1,l2;
        for(int i=0;i<list1.size();i++){
            l1[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            if(l1.find(list2[i])!=l1.end()){
                if(leastSum>i+l1[list2[i]]){
                    res={list2[i]};
                    leastSum=i+l1[list2[i]];
                }else if(leastSum==i+l1[list2[i]]){
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
