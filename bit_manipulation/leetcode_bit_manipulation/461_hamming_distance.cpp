//
//  461_hamming_distance.cpp
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
    int hammingDistance(int x, int y) {
        int count=0;
        int data=x^y;
        for(int i=0;i<32;i++){
            if(data&1<<i){
                count++;
            }
        }
        return count;
    }
};
