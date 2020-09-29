//
//  codility_test.cpp
//  leetcode_tree
//
//  Created by Hadley on 27.09.20.
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

struct tree {
     int x;
     tree *l;
     tree *r;
};

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

//int d[30];
//int l = 0;
//int n=955;
//while (n > 0) {
//    d[l] = n % 2;
//    n /= 2;
//    l++;
//}
//for(int i=0;i<10;i++){
//    cout<<d[i]<<endl;
//}

vector<int> solution(vector<int> &A, int F, int M) {
    // write your code in C++14 (g++ 6.2.0)
    int n=A.size();
    int total=n+F;
    int sum=M*total;

    int s=0;
    for(auto &x:A){
        s+=x;
    }
    int target=sum-s;
    
    int m=1000000007;
    vector<vector<int> > dp(F+1, vector<int>(target+1, 0));
    dp[0][0]=1;
    vector<int>res;
    for(int i=1; i<=F; i++){
        for(int j=1; j<=target; j++){
            for(int k=1; k<=6; k++){
                if(k<=j)
                    dp[i][j]=((dp[i][j]%m)+(dp[i-1][j-k]%m))%m;
            }
        }
    }

    if(dp[F][target]==0){
        return {-1};
    }else{
        int cnt=1;
        while(target){
            for(int k=1;k<=6;k++){
                if(k<=target&&dp[F-cnt][target-k]){
                    res.push_back(k);
                    cnt++;
                    target=target-k;
                    break;
                }
            }
        }
        return res;
    }
}

