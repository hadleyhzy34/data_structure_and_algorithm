//
//  167_two_sum_2.cpp
//  leetcode_array
//
//  Created by Hadley on 27.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
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

class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>map;
        for(int i=0;i<numbers.size();i++){
            if(map.find(target-numbers[i])!=map.end()){
                return {map[target-numbers[i]],i+1};
            }
            map[numbers[i]]=i+1;
        }
        return {0,0};
    }
};
