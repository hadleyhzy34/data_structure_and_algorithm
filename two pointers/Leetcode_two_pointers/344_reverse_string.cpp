//
//  344_reverse_string.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 14.08.20.
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
    void reverseString(vector<char>& s) {
        char temp;
        auto n=s.size();
        int l=0,r=n-1;
        while(l<r){
            temp=s[l];
            s[l]=s[r];
            s[r]=temp;
            l++;
            r--;
        }
    }
};
