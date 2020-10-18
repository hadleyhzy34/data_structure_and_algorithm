//
//  209_minimum_size_subarray_sum.cpp
//  leetcode_array
//
//  Created by Hadley on 14.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//
#include "/usr/local/include/stdc++.h"
#include <iostream>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())return 0;
        int start=0;
        int end=0;
        
        int cur=nums[0];
        int minLength=0;
        while(end!=nums.size()){
            if(cur>=s){
                if((end-start)==0){
                    return 1;
                }else{
                    if((cur-nums[start])>=s){
                        cur-=nums[start];
                        start=start+1;
                    }else{
                        if(minLength){
                            minLength=min(minLength,end-start+1);
                        }else{
                            minLength=end-start+1;
                            cout<<start<<" "<<end<<endl;
                        }
                        if(end==nums.size()-1){
                            break;
                        }else{
                            end++;
                            cur+=nums[end];
                        }
                    }
                }
            }else{
                if(end==nums.size()-1){
                        break;
                }else{
                        end++;
                        cur+=nums[end];
                }
            }
        }
        return minLength;
    }
};

//two pointers
class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())return 0;
        int j=0;
        int min_length=INT_MAX;
        int n=nums.size();
        int cur=0;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            if(cur>=s){
                while(cur-nums[j]>=s){
                    cur=cur-nums[j];
                    j++;
                }
                min_length=min(min_length,i-j+1);
            }
        }
        return min_length==INT_MAX?0:min_length;
    }
};

//binary search
class Solution209_3 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())return 0;
        int n=nums.size();

        int ans=INT_MAX;
        std::vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }

        for(int i=1;i<=n;i++){
            int to_find=s+sum[i-1];
            auto bound=lower_bound(sum.begin(),sum.end(),to_find);
            if(bound!=sum.end()){
                auto it = bound-sum.begin();
//                ans=min(ans,static_cast<int>(bound-(sum.begin()+i-1)));
                ans=min(long(ans),bound-(sum.begin()+i-1));
            }
        }
        return ans==INT_MAX?0:ans;
    }
};






