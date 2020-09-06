//
//  311_sparse_matrix_multiplication.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 19.08.20.
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
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        auto m=A.size();
        auto n=A[0].size();
        auto l=B[0].size();
        vector<vector<int>>res(m,vector<int>(l,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<l;k++){
                    res[i][k]+=A[i][j]*B[j][k];
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        auto m=A.size();
        auto n=A[0].size();
        auto l=B[0].size();
        vector<vector<int>>res(m,vector<int>(l,0));
        unordered_map<int, vector<pair<int,int>>>map;
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                if(B[i][j]){
                    map[i].push_back(make_pair(j, B[i][j]));
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]){
                    auto it=map.find(j);
                    if(it!=map.end()){
                        int count=0;
                        while(count<it->second.size()){
                            res[i][it->second[count].first]+=A[i][j]*(it->second[count].second);
                            cout<<i<<" "<<j<<" "<<it->second[count].first<<" "<<it->second[count].second<<" "<<res[i][it->second[count].first]<<endl;
                            count++;
                        }
                    }
                }
            }
        }
        return res;
    }
};
