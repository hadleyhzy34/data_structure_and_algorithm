//
//  209_minimum_size_subarray_sum.cpp
//  binary_search
//
//  Created by Hadley on 08.08.20.
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
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=0;
        int end=0;
        
        int cur=nums[0];
        int minLength=0;
        while(end!=nums.size()-1){
            // cout<<cur<<" "<<start<<" "<<end<<" "<<endl;
            if(cur>=s){
                if((end-start)==0){
                    return 1;
                }else{
                    if((cur-nums[start])>=s){
                        start=start+1;
                    }else{
                        if(!minLength){
                            minLength=min(minLength,end-start+1);
                        }else{
                            minLength=end-start+1;
                        }
                        end++;
                    }
                }
            }else{
                end++;
                cur+=nums[end];
            }
            // cout<<cur<<" "<<start<<" "<<end<<" "<<endl;
        }
        return minLength;
    }
};
