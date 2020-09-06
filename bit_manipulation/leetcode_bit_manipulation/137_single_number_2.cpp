//
//  137_single_number_2.cpp
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
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        int ones = 0, twos = 0, mask = 0;
        
        for (int i = 0; i < n; i++) {
            twos |= ones & nums[i];
            cout<<twos<<endl;
            ones ^= nums[i];
            cout<<ones<<endl;
            mask = ~(ones & twos);
            ones = ones & mask;
            twos = twos & mask;
            cout<<mask<<" "<<twos<<" "<<ones<<endl;
        }
        
        return ones;
    }
};
