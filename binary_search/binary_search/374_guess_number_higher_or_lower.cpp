//
//  374_guess_number_higher_or_lower.cpp
//  binary_search
//
//  Created by Hadley on 05.08.20.
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


//Forward declaration of guess API.
//@param  num   your guess
//@return          -1 if num is lower than the guess number
//                  1 if num is higher than the guess number
//              otherwise return 0
int guess(int num);
 

class Solution {
public:
    int guessNumber(int n) {
        if(n==1)return 1;
        int l=0;
        int r=n;
        while(l<=r){
            int m=l+(r-l)/2;
            if(guess(m)==0){
                return m;
            }else if(guess(m)==-1){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return 0;
    }
};
