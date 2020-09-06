//
//  168_excel_sheet_column_title.cpp
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
    string convertToTitle(int n) {
        string res;
        if(n==1)return "A";
        n=n-1;
        while(n>=0){
                char a='A'+n%26;
                res=a+res;
                n=n/26-1;
        }
        return res;
    }
};
