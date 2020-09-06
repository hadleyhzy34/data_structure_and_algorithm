//
//  274_H_index.cpp
//  leetcode_sort
//
//  Created by Hadley on 22.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max;
        if(!citations.size())return 0;
        if(citations.size()==1&&citations[0]==0)return 0;
        //number of books
        int N=citations.size();
        sort(citations.begin(),citations.end());
        for(int h=1;h<=citations.size();h++){
            if(citations[N-h]>=h)
                max=h;
        }
        return max;
    }
};
