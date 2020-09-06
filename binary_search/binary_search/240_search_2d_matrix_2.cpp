//
//  240_search_2d_matrix_2.cpp
//  binary_search
//
//  Created by Hadley on 09.08.20.
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())return false;
        int m=matrix.size();
        int n=matrix[0].size();
        if(target<matrix[0][0]||target>matrix[m-1][n-1])return false;
        
//        int start_l=m,end_l=0;
//        int start_r=m,end_r=0;
//
//        for(int i=0;i<m;i++){
//            if(matrix[i][0]<target){
//                start_l=min(start_l,i);
//                end_l=max(end_l,i);
//            }
//            if(matrix[i][n-1]>target){
//                start_r=min(start_r,i);
//                end_r=max(end_r,i);
//            }
//            if(matrix[i][0]==target||matrix[i][n-1]==target)return true;
//        }
        
        int start_l=0,end_l=0;
        int start_r=m,end_r=n-1;
        
        for(int i=0;i<m;i++){
            if(matrix[i][0]<target){
                end_l=max(end_l,i);
            }
            if(matrix[i][n-1]>target){
                start_r=min(start_r,i);
            }
            if(matrix[i][0]==target||matrix[i][n-1]==target)return true;
        }
        
        int l=max(start_r,start_l);
        int r=min(end_r,end_l);
        
        if(l>r)return false;
        for(int i=l;i<=r;i++){
            int ll=0,rr=n-1;
            while(ll<=rr){
                int mid=ll+(rr-ll)/2;
                if(matrix[i][mid]==target){
                    return true;
                }else if(matrix[i][mid]<target){
                    ll=mid+1;
                }else{
                    rr=mid-1;
                }
            }
        }
        return false;
    }
};


class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())return false;
        int m=matrix.size();
        int n=matrix[0].size();
        if(target<matrix[0][0]||target>matrix[m-1][n-1])return false;
        
        int start_l=0,end_l=n-1;
        int start_r=0,end_r=n-1;
        
        while(start_l<end_l){
            int m=start_l+(end_l-start_l)/2;
            if(matrix[m][0]==target){
                return true;
            }else if(matrix[m][0]<target){
                if(matrix[m+1][0]>target){
                    end_l=m;
                    break;
                }else{
                    start_l=m+1;
                }
            }else{
                end_l=m-1;
            }
        }
        
        while(start_r<end_r){
            int m=start_r+(end_r-start_r)/2;
            if(matrix[m][n-1]==target){
                return true;
            }else if(matrix[m][n-1]>target){
                if(matrix[m+1][n-1]<target){
                    end_r=m;
                    break;
                }else{
                    start_r=m+1;
                }
            }else{
                end_r=m-1;
            }
        }
        
        
        
        int l=max(start_r,0);
        int r=min(n-1,end_l);
        
        if(l>r)return false;
        for(int i=l;i<=r;i++){
            int ll=0,rr=n-1;
            while(ll<=rr){
                int mid=ll+(rr-ll)/2;
                if(matrix[i][mid]==target){
                    return true;
                }else if(matrix[i][mid]<target){
                    ll=mid+1;
                }else{
                    rr=mid-1;
                }
            }
        }
        return false;
    }
};
