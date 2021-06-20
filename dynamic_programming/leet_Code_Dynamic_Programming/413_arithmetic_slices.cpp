//
//  413_arithmetic_slices.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 21.07.20.
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
    int numberOfArithmeticSlices(vector<int>& A) {
        auto n=A.size();
        vector<int> temp(n,0);
        vector<vector<int>> L(n,temp);
        int count=0;
        
        for(int i=0;i+1<n;i++){
            for(int j=i+1;j<n;j++){
                if(j==i+1){
                    L[i][j]=1;
                    continue;
                }
                if((A[j]-A[j-1])==(A[j-1]-A[j-2])&&L[i][j-1]==1){
                    L[i][j]++;
                }
                count+=L[i][j];
            }
        }
        return count;
    }
};
