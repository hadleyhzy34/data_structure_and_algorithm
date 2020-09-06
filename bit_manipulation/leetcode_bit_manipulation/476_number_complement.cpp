//
//  476_number_complement.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int lead=0;
        for(int i=0;i<32;i++){
            if(num&1<<(32-i-1)){
                lead=32-i;
                break;
            }
        }
        int output=0;
        for(int i=0;i<lead;i++){
            if(num&1<<i){
            }else{
                output+=(1<<i);
            }
        }
        return output;
    }
};
