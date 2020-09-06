//
//  27_remove_element.cpp
//  leetcode_array
//
//  Created by Hadley on 16.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution27 {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        if(nums.size()==0){return 0;}
        if(nums[0]==val&&nums.size()==1){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
//            cout<<i<<" "<<nums[count]<<endl;
            if(nums[i]!=val){
                nums[count++]=nums[i];
//                cout<<i<<" "<<nums[count]<<endl;
            }
        }
        return count;
    }
};



class Solution27_1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        if(nums.size()==0){return 0;}
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[count++]=nums[i];
            }
        }
        return count;
    }
};

class Solution27_2 {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val),nums.end());
        return nums.size();
    }
};

