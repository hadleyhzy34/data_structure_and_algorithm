//
//  516_longest_palindromic_subsequence.cpp
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
    int longestPalindromeSubseq(string s) {
        if(s.empty())return 0;
        vector<int> L(s.length(),1);
        int maxLength=1;
        
        for(int i=1;i<s.length()-1;i++){
            int m=i;
            int n=i-1;
            bool even=true;
            while(m<s.length()&&n>=0){
                if(s[m]==s[n]){
                    m++;
                    n--;
                    L[i]++;
                }else if(even){
                    m++;
                    even=false;
                }else if(!even){
                    n++;
                    even=true;
                }
            }
            maxLength=max(maxLength,L[i]);
        }
        return maxLength;
    }
};

class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())return 0;
        auto n=s.length();
        int L[n][n];
        memset(L, 0, sizeof(L));
        
        for(int i=0;i<n;i++){
            L[i][i]=1;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                L[i][i+1]=2;
            }else{
                L[i][i+1]=1;
            }
        }
        
        for(int l=2;l<n;l++){
            for(int i=0;i+l<n;i++){
                if(s[i]==s[i+l]){
                    L[i][i+l]=L[i+1][i+l-1]+2;
                }else{
                    L[i][i+l]=max(L[i+1][i+l],L[i][i+l-1]);
                }
            }
        }
        return L[0][n-1];
    }
};
