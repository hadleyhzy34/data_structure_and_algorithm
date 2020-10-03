//
//  5_longest_palindromic_substring.cpp
//  string
//
//  Created by Hadley on 02.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())return "";
        auto n=s.size();
        bool dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int maxLength=1;
        int index=0;
        
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                if(s[i]==s[i+l-1]&&(l==2||dp[i+1][i+l-2]==true)){
                    dp[i][i+l-1]=true;
                    if(l>maxLength){
                        maxLength=l;
                        index=i;
                    }
                }else{
                    dp[i][i+l-1]=false;
                }

            }
        }
        return s.substr(index,maxLength);
//        for(int i=0;i<n;i++){
//            for(int l=2;i+l-1<n;l++){
//                cout<<i<<" "<<l<<endl;
//                if(s[i]==s[i+l-1]&&(l==2||dp[i+1][i+l-2]==true)){
//                    cout<<i<<" "<<l<<maxLength<<endl;
//                    dp[i][i+l-1]=true;
//                    if(l>maxLength){
//                        maxLength=l;
//                        res=s.substr(i,l);
//                    }
//                }else{
//                    dp[i][i+l-1]=false;
//                }
//            }
//        }
//        return res;
    }
};
