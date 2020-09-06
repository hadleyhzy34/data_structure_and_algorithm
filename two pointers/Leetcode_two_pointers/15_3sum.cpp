//
//  15_3sum.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 14.08.20.
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
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
          // nums.resize(std::distance(nums.begin(), std::unique(nums.begin(), nums.end())));
         
          auto n=nums.size();
          vector<vector<int>>res;
          int i=0,j=1,k=2;
          while(i+2<n){
              if(nums[i]>0){
                  break;
              }else if(nums[i]+nums[j]+nums[k]>0){
                  if(j+2<n){
                      j++;k=j+1;
                  }else{
                      i++;j=i+1;k=i+2;
                  }
              }else if(nums[i]+nums[j]+nums[k]<=0){
                  if(nums[i]+nums[j]+nums[k]==0){
                      res.push_back({nums[i],nums[j],nums[k]});
                  }
                  if(k+1<n){
                      k++;
                  }else if(j+2<n){
                      j++;k=j+1;
                  }else{
                      i++;j=i+1;k=i+2;
                  }
              }
          }
         
         
//         for(auto x:res){
//             for(auto y:x){
//                 cout<<y<<" ";
//             }
//             cout<<endl;
//         }
//
//          sort(res.begin(),res.end(),[](vector<int>&a,vector<int>&b){
//             if(a[0]==b[0]){
//                 if(a[1]==b[1]){
//                     return a[2]<b[2];
//                 }else{
//                     return a[1]<b[1];
//                 }
//             }else{
//                 return a[0]<b[0];
//             }
//          });
//
//          for(int i=1;i<res.size();i++){
//              if(res[i]==res[i-1]){
//                  res.erase(res.begin()+i);
//                  i--;
//              }
//          }
//         for(auto x:res){
//             for(auto y:x){
//                 cout<<y<<" ";
//             }
//             cout<<endl;
//         }
          return res;
    }
};
