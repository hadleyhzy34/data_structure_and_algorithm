//
//  371_sum_of_two_integers.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 07.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution371 {
public:
    int getSum(int a, int b) {
        int output=a;
        while(b){
            unsigned int temp=(unsigned)(output&b)<<1;
            cout<<output<<" "<<b<<" ";
            output=output^b;
            b=temp;
            cout<<output<<" "<<b<<endl;
        }
        return output;
    }
};
