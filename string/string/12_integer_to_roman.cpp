//
//  12_integer_to_roman.cpp
//  string
//
//  Created by Hadley on 04.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<string> d={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> n={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        int index=0;
        while(num>0){
            while(num>=n[index]){
                num-=n[index];
                res+=d[index];
            }
            index++;
        }
        return res;
    }
};
