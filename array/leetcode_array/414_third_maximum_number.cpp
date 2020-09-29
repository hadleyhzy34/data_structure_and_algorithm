//
//  414_third_maximum_number.cpp
//  leetcode_array
//
//  Created by Hadley on 20.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution414 {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()<3){return *max_element(nums.begin(), nums.end());}
        vector<int> max;
        for(auto num:nums){
            cout<<num<<endl;
            if(max.empty()){
                max.push_back(num);
                continue;
            }
            switch (max.size()) {
                case 1:
                    if(num>max[0]){
                        max.push_back(max[0]);
                        max[0] = num;
                    }
                    if(num<max[0]){
                        max.push_back(num);
                    }
                    break;
                case 2:
                    if(num>max[0]){
                        max.push_back(max[1]);
                        max[1] = max[0];
                        max[0] = num;
                    }else if(max[1]<num&&num<max[0]){
                        max.push_back(max[1]);
                        max[1] = num;
                    }else if(num<max[1]){
                        max.push_back(num);
                    }
                    break;
                case 3:
                    if(num>max[0]){
                        max[2] = max[1];
                        max[1] = max[0];
                        max[0] = num;
                    }else if(max[1]<num&&num<max[0]){
                        max[2] = max[1];
                        max[1] = num;
                    }else if(max[2]<num&&num<max[1]){
                        max[2] = num;
                    }
                    break;
                default:
                    break;
            }
        }
        if(max.size()<3){
            return max[0];
        }else{
            return max[2];
        }
    }
};


//using minimum integer number of limits solution2

//
//using max heap sort
//if all numbers are distinct and it returned third maximum distinct number
class solution414_2{
public:
    int thirdMax(vector<int>&nums){
        if(nums.size()==2)return (nums[0]<nums[1])?nums[1]:nums[0];
        make_heap(nums.begin(), nums.end());
        
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
        return nums.front();
    }
};

class solution414_3{
public:
    int thirdMax(vector<int>&nums){
        unordered_map<int, int>map;
        std::min(nums.begin(), nums.end());
        int min=*min_element(nums.begin(), nums.end());
        int max=*max_element(nums.begin(), nums.end());
        
        for(auto &x:nums){
            map[x]++;
        }
        
        int cnt=0;
        int j=0;
        for(int i=max;i>=min;i--){
            if(map.find(i)!=map.end()){
                cnt++;
                j=i;
                if(cnt==3){
                    return nums[i];
                }
            }
        }
        return nums[j];
    }
};

class solution414_4{
public:
    int thirdMax(vector<int>&nums){
        long one=LONG_MIN,two=LONG_MIN,three=LONG_MIN;
        int i=0;
        while(i<nums.size()){
            if(nums[i]>one){
                three=two;
                two=one;
                one=nums[i];
            }else if(nums[i]<one&&nums[i]>two){
                three=two;
                two=nums[i];
            }else if(nums[i]<two&&nums[i]>three){
                three=nums[i];
            }
            i++;
        }
        //we use long_min in case that third number itself is INT_MIN
        return three==LONG_MIN?one:three;
    }
};
