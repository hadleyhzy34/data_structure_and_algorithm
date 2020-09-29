//
//  118_Pascal_triangle.cpp
//  leetcode_array
//
//  Created by Hadley on 17.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution118 {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows){return vector<vector<int>>{0};}
        vector<vector<int>> nums(numRows);
        nums[0].push_back(1);
        int row = 0;
        while(row<numRows-1){
            for(int col=0;col<nums[row].size();col++){
                if(col==0){nums[row+1].push_back(1);}else{
                    nums[row+1].push_back(nums[row][col]+nums[row][col-1]);}
            }
            nums[row+1].push_back(1);
            row++;
        }
        return nums;
    }
};

class Solution118_2 {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows){return vector<vector<int>>{0};}
        vector<vector<int>> nums(numRows);
        nums[0].push_back(1);
        
        for(int i=1;i<numRows;i++){
            nums[i].push_back(1);
            int n=nums[i-1].size();
            for(int j=0;j<n-1;j++){
                nums[i].push_back(nums[i-1][j]+nums[i-1][j+1]);
            }
            nums[i].push_back(1);
        }
        return nums;
    }
};
