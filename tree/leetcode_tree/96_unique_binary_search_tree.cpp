//
//  429_nary_tree_level_order_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 11.07.20.
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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    Solution():count(1024,1){
    }
    
    int countTrees(int n){
        if(!n)return 1;
        if(count[n]!=1)return count[n];
        
        count[n]=0;
        for(int i=1;i<=n;i++){
            count[n]+=countTrees(i-1)*countTrees(n-i);
        }
        return count[n];
    }
    int numTrees(int n) {
//        for(int i=0;i<1024;i++)
//            count[i] = 1;
        return countTrees(n);
    }
private:
    vector<int> count;
};


class Solution2 {
public:
    int dfs(int l,int r){
        int res=0;
        if(l>r){
            return 1;
        }
        for(int i=l;i<=r;i++){
            int ll=dfs(l,i-1);
            int rr=dfs(i+1,r);
            res+=ll*rr;
        }
        return res;
    }
    int numTrees(int n) {
        if(n==0)return 0;
        return dfs(1,n);
    }
};

class Solution3 {
public:
    int numTrees(int n) {
        if(n==0)return 0;
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int l=1;l<=n;l++){
            for(int i=1;i+l-1<=n;i++){
                if(l==1){
                    dp[i][i+l-1]=1;
                }else{
                    for(int j=i;j<=i+l-1;j++){
                        if(j==i){
                            dp[i][i+l-1]+=dp[j+1][i+l-1];
                        }else if(j==i+l-1){
                            dp[i][i+l-1]+=dp[i][j-1];
                        }else{
                            dp[i][i+l-1]+=dp[i][j-1]*dp[j+1][i+l-1];
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};

