//
//  454_4sum_2.cpp
//  binary_search
//
//  Created by Hadley on 11.08.20.
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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.empty())return 0;
        sort(A.begin(), A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());
        
        int output=0;
        for(auto i:A){
            for(auto j:B){
                for(auto k:C){
                    for(auto l:D){
                        if(i+j+k+l==0)output++;
                    }
                }
            }
        }
        return output;
    }
};

class Solution2 {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.empty())return 0;
//        sort(A.begin(), A.end());
//        sort(B.begin(),B.end());
//        sort(C.begin(),C.end());
//        sort(D.begin(),D.end());
        
        int output=0;
        unordered_map<int, int>first;
        unordered_map<int, int>second;
        int maxl=0;
        
        for(auto i:A){
            for(auto j:B){
                first[i+j]++;
                maxl=min(maxl,i+j);
            }
        }
        
        for(auto k:C){
            for(auto l:D){
                second[k+l]++;
                maxl=min(maxl,k+l);
            }
        }
        
        for(int i=0;i<=maxl;i++){
            if(i==0){
                output+=first[0]*second[0];
            }else{
                output+=first[i]*second[-i]+first[-i]*second[i];
            }
        }
        
        return output;
    }
};


class Solution3 {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.empty())return 0;
//        sort(A.begin(), A.end());
//        sort(B.begin(),B.end());
//        sort(C.begin(),C.end());
//        sort(D.begin(),D.end());
        
        int output=0;
        unordered_map<int, int>first;
        unordered_map<int, int>second;
        int maxl=0;
        
        for(auto i:A){
            for(auto j:B){
                first[i+j]++;
                maxl=min(maxl,i+j);
            }
        }
        
        for(auto k:C){
            for(auto l:D){
                second[k+l]+=first[-(k+l)];
                maxl=min(maxl,k+l);
            }
        }
        
        for(auto i:second){
            output+=i.second;
        }
        
        return output;
    }
};
