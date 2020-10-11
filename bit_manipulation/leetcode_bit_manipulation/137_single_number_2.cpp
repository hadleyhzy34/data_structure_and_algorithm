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

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>map;
        int res=0;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            if(map[nums[i]]<=2){
                res^=nums[i];
            }
        }
        return res;
    }
};

class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once=0, seen_twice=0;

        for(int i=0;i<nums.size();i++){
            seen_once=~seen_twice&(seen_once^nums[i]);
            seen_twice=~seen_once&(seen_twice^nums[i]);
            
        }
        return seen_once;
    }
};

