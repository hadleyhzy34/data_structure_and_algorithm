//
//  189_rotate_array.cpp
//  leetcode_array
//
//  Created by Hadley on 18.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution189_1 {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i=0;i<k;i++){
            nums.insert(nums.begin(), *(nums.end()-1));
            nums.erase(nums.end()-1);
        }
    }
};

class Solution189_2 {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size())
        k=k%nums.size();
        std::rotate(nums.begin(),nums.begin()+nums.size()-k,nums.end());
    }
};

class Solution189_3 {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size())
        k=k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
