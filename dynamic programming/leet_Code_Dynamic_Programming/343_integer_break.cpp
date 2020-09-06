//
//  343_integer_break.cpp
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
    int integerBreak(int n) {
        if(!n)return 0;
        int count[n+1];
        memset(count, 0, sizeof(count));
        count[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                int temp_product=max(count[j],j)*max(count[i-j],(i-j));
                if(count[i]<temp_product)count[i]=temp_product;
            }
            cout<<i<<" "<<count[i]<<endl;
        }
        return count[n];
    }
};
