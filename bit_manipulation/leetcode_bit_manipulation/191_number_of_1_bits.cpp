//
//  191_number_of_1_bits.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 07.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=0;i<32;i++){
            if(n&1<<i){
                count++;
            }
        }
        return count;
    }
};
