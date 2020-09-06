//
//  167_two_sum.cpp
//  leetcode_array
//
//  Created by Hadley on 18.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size()-1;i++){
            for(int j=i+1;j<numbers.size();j++){
                if(numbers.at(i)+numbers.at(j)==target){
                    return vector<int> {i,j};
                }
            }
        }
        return vector<int> {0};
    }
};

class Solution167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(numbers.size()-1);
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                return vector<int>{left+1, right+1};
            }else if(numbers[left]<target-numbers[right]){
                left++;
            }else{
                right--;
            }
        }
        return vector<int>{0,0};
    }
};
