//
//  375_guess_number_higher_or_lower_2.cpp
//  Minimax
//
//  Created by Hadley on 04.08.20.
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
    int getMoneyAmount(int n) {
        if(n==1)return 0;
        int x=n/2+1;
        int total=x;
        while(x!=n){
            x=(n+x)/2+1;
        }
        return total;
    }
};
