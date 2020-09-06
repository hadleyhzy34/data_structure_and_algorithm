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
//    int uniquePaths(int m, int n) {
//        if(m==1)return 1;
//        if(n==1)return 1;
//        return uniquePaths(m-1, n)+uniquePaths(m, n-1);
//    }
//};

class Solution62_1 {
public:
    int uniquePaths(int m, int n) {
        if(m==1)return 1;
        if(n==1)return 1;
        int pathWay[m+1][n+1];

        for(int i=1;i<=m;i++){
            pathWay[i][1]=1;
        }
        for(int i=1;i<=n;i++){
            pathWay[1][i]=1;
        }
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                pathWay[i][j]=pathWay[i-1][j]+pathWay[i][j-1];
            }
        }
        return pathWay[m][n];
    }
};
