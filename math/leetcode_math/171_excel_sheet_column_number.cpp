//
//  171_excel_sheet_column_number.cpp
//  leetcode_math
//
//  Created by Hadley on 11.08.20.
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
    int titleToNumber(string s) {
        int res=0;
        for(auto it=s.begin();it!=s.end();it++){
            int temp=*it-'A'+1;
            res=res*26+temp;
        }
        return res;
    }
};
