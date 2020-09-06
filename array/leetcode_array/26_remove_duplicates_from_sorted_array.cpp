//
//  26_remove_duplicates_from_sorted_array.cpp
//  leetcode_array
//
//  Created by Hadley on 16.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        for(auto it=nums.begin();it!=nums.end()-1;it++){
            cout<<"during loop "<<*it<<" "<<*(it+1)<<endl;
            if(*(it)==*(it+1)){
                cout<<"before erase"<<*it<<" "<<*(it+1)<<endl;
                nums.erase(it);
                it--;
                cout<<"after erase"<<*it<<" "<<*(it+1)<<endl;
            }
        }
        return static_cast<int>(nums.size());
    }
};


class Solution26_1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        if(nums.size()==0){return 0;}
        for(auto &num:nums){
            if(num!=nums[count]){
                nums[++count]=num;
            }
        }
        return count+1;
    }
};

class Solution26_2 {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it_end = unique(nums.begin(), nums.end());
        nums.erase(it_end, nums.end());
        return static_cast<int>(nums.size());
    }
};

class Solution26_3 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        int count = 0;
        auto end = unique(nums.begin(), nums.end());
        for(auto it = nums.begin();it!=end;++it){
            count++;
        }
        return count;
    }
};
