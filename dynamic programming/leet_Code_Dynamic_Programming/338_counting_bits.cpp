//
//  338_counting_bits.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 20.07.20.
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
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for(int i=1;i<=num;i++){
            if(i&1){
                res.push_back(res[i-1]+1);
            }else{
                int l=log2(i);
                if(ceil(log2(i)) == floor(log2(i))){
                    res.push_back(1);
                }else{
                    res.push_back(1+res[i-pow(2,l)]);
                }
            }
        }
        return res;
    }
};
