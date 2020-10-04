//
//  74_search_a_2d_array.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       if(matrix.empty()||matrix[0].empty())return false;
       //find rows, top returns the first row that is larger than target
       int top=0,bot=matrix.size()-1;
       while(top<=bot){
           int m=top+(bot-top)/2;
           if(matrix[m][0]<=target){
               top=m+1;
           }else{
               bot=m-1;
           }
       }

       if(top>matrix.size())return false;
       top--;
       if(top<0)return false;

       int l=0, r=matrix[0].size()-1;
       while(l<=r){
           int m=l+(r-l)/2;
           if(matrix[top][m]==target){
               return true;
           }else{
               if(matrix[top][m]<target){
                   l=m+1;
               }else{
                   r=m-1;
               }
           }
       }
       return false;
    }
};
