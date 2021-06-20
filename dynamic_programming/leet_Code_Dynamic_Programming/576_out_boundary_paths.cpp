//
//  576_out_boundary_paths.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 04.08.20.
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
    int findPaths(int m, int n, int N, int i, int j) {
        cout<<i<<" "<<j<<" "<<N<<endl;
            if((i<0||j<0||i>=m||j>=n)&&(N>=0)) return 1;
            if(i>=0&&j>=0&&i<m&&j<n&&N==0) return 0;
            return findPaths(m,n,N-1,i-1,j)+findPaths(m,n,N-1,i,j-1)+findPaths(m,n,N-1,i+1,j)+findPaths(m,n,N-1,i,j+1);
        }
};

class Solution2 {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        long long int L[m+2][n+2][N+1];
        memset(L, 0, sizeof(L));
        
        for(int l=0;l<=N;l++){
            for(int i=0;i<=m+1;i++){
                for(int j=0;j<=n+1;j++){
                    if(i==0||i==m+1||j==0||j==n+1){
                        L[i][j][l]=1;
                    }else{
                        L[i][j][l]=0;
                    }
                }
            }
        }
        
        constexpr int mod(1e9 + 7);
        
        for(int l=1;l<=N;l++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    // if(i==2&&j==1){
                    //     cout<<L[i+1][j][l-1]<<" "<<L[i][j+1][l-1]<<" "<<L[i][j-1][l-1]<<" "<<L[i-1][j][l-1]<<endl;
                    // }
                    L[i][j][l]=(L[i+1][j][l-1]+L[i][j+1][l-1]+L[i][j-1][l-1]+L[i-1][j][l-1])%mod;
                }
            }
        }
        return L[i+1][j+1][N];
    }
};


