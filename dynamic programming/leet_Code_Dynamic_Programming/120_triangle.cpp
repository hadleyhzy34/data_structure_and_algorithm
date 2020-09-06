//
//  62_unique_paths.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 14.07.20.
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


//class Solution {
//public:
//    int minimumTotal(vector<vector<int>>& triangle) {
//        if(triangle.empty())return 0;
//        vector<int> res;
//        res[0]=triangle[0][0];
//
//        for(int i=1;i<triangle.size();i++){
//            res[i]=res[i-1]
//        }
//    }
//};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())return 0;
        if(triangle.size()==1)return triangle[0][0];
        
        vector<vector<int>> minSum=triangle;
        minSum[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                    minSum[i][0]=minSum[i-1][0]+triangle[i][0];
                }else if (j==triangle[i].size()-1){
                    minSum[i][j]=minSum[i-1][j-1]+triangle[i][j];
                }else{
                    minSum[i][j]=min(minSum[i-1][j],minSum[i-1][j-1])+triangle[i][j];
                }
            }
        }
        return *min_element(minSum[triangle.size()-1].begin(), minSum[triangle.size()-1].end());
    }
};




