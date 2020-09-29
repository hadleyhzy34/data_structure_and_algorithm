//
//  583_delete_operation_for_two_strings.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size()+1][word2.size()+1];
        for(int i=0;i<=word1.size();i++){
            for(int j=0;j<=word2.size();j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }else if(word1[i]==word2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return word1.size()+word2.size()-2*dp[word1.size()][word2.size()];
    }
};
