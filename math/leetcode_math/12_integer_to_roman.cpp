//
//  12_integer_to_roman.cpp
//  leetcode_math
//
//  Created by Hadley on 12.08.20.
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
    string intToRoman(int num) {
        string res;
        
        unordered_map<int,string>dict;
        dict[4]="IV";
        dict[9]="IX";
        dict[40]="XL";
        dict[90]="XC";
        dict[400]="CD";
        dict[900]="CM";
        dict[1]="I";
        dict[5]="V";
        dict[10]="X";
        dict[50]="L";
        dict[100]="C";
        dict[500]="D";
        dict[1000]="M";
        
        
        vector<int>l{1000,900,500,400,100,90,50,40,10,5,4,1};
        for(int i=0;i<l.size();i++){
            while(num/l[i]!=0){
                res.append(dict[l[i]]);
                num=num-l[i];
            }
        }
        return res;
    }
};
