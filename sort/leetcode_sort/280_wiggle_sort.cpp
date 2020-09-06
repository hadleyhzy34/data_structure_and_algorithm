//
//  280_wiggle_sort.cpp
//  leetcode_sort
//
//  Created by Hadley on 22.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
    public:
        void wiggleSort(vector<int>& nums) {
            std::sort(nums.begin(),nums.end());
            if(nums.size()<=2) return;

            vector<int> front(nums.begin(),nums.begin()+nums.size()/2+nums.size()%2);
            vector<int> end(nums.begin()+nums.size()/2+nums.size()%2,nums.end());

            bool flip=true;
            int count=0;

            for(int i=0;i<nums.size();i++){
                if(flip){
                    nums[i]=front[front.size()-1-count];
                    flip=false;
                }else{
                    nums[i]=end[end.size()-1-count];
                    flip=true;
                    count++;
                }
            }
        }
};


class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
            std::sort(nums.begin(),nums.end());
            if(nums.size()<=2) return;

            vector<int> front(nums.begin(),nums.begin()+nums.size()/2+nums.size()%2);
            vector<int> end(nums.begin()+nums.size()/2+nums.size()%2,nums.end());

            int count=0;

            for(int i=0;i<end.size();i++){
                nums[count]=front[front.size()-1-i];
                nums[++count]=end[end.size()-1-i];
                count++;
            }
            if(end.size()<front.size()){
                nums[count]=front[0];
            }
    }
};

class Solution3 {
public:
    void wiggleSort(vector<int>& nums) {
            std::sort(nums.begin(),nums.end());
            if(nums.size()<=2) return;

            vector<int> front(nums.begin(),nums.begin()+nums.size()/2+nums.size()%2);
            vector<int> end(nums.begin()+nums.size()/2+nums.size()%2,nums.end());

            int count=0;

            for(int i=0;i<end.size();i++){
                nums[count]=front[front.size()-1-i];
                nums[++count]=end[end.size()-1-i];
                count++;
            }
            if(end.size()<front.size()){
                nums[count]=front[0];
            }
    }
};


class Solution4 {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<=2) return;
        std::nth_element(nums.begin(), nums.begin()+nums.size()/2+nums.size()%2,nums.end(),[](int i,int j){return i<=j;});
        std::vector<int>small;
        std::vector<int>large;
        for(auto n:nums){
            if(n<=nums[nums.size()/2+nums.size()%2-1]){
                small.push_back(n);
            }else{
                large.push_back(n);
            }
        }
        
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i&1){
                nums[i]=large[count];
                count++;
            }else{
                nums[i]=small[count];
            }
        }
    }
};
