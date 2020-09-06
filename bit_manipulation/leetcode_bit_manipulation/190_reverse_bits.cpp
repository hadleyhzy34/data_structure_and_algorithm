//
//  190_reverse_bits.cpp
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

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t output=0;;
        for(int i=0;i<32;i++){
            if(n&1<<i){
                output+=1<<(32-i-1);
            }
        }
        return output;
    }
};
