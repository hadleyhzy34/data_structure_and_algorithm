//
//  453_minimum_moves_to_equal_array_elements.cpp
//  leetcode_math
//
//  Created by Hadley on 13.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(std::equal(nums.begin()+1, nums.end(), nums.begin()))return 0;
        long long sum=0,count,n=nums.size(),mi=nums[0],ma=nums[0];
        for(auto x:nums){
            sum+=x;
            if(x<mi)mi=x;
            // if(x>ma)ma=x;
        }
        count=sum-n*mi;
        // cout<<"sum is "<<sum<<" "<<count<<endl;
        // cout<<floor(((n-1)*count+sum)/n)<<" "<<ceil(((n-1)*count+sum)/n)<<endl;
        // while(((n-1)*count+sum)%n!=0)count++;
        // cout<<count<<endl;
        return count;
    }
};
