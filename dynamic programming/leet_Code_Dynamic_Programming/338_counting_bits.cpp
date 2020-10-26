//
//  338_counting_bits.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 20.07.20.
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
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for(int i=1;i<=num;i++){
            if(i&1){
                res.push_back(res[i-1]+1);
            }else{
                int l=log2(i);
                if(ceil(log2(i)) == floor(log2(i))){
                    res.push_back(1);
                }else{
                    res.push_back(1+res[i-pow(2,l)]);
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> countBits(int num) {
        if(num==0)return{0};
        vector<int> dp(num+1,0);
        dp[0]=0;
        dp[1]=1;
        int count=1;
        for(int i=2;i<=num;i++){
            if(i>=pow(2,count+1)){
                count++;
            }
            dp[i]=dp[i%int(pow(2,count))]+1;
        }
        return dp;
    }
};


//count all bits except at position 0, then plus(1&i)
class Solution3 {
public:
    vector<int> countBits(int num) {
        if(num==0)return{0};
        vector<int> dp(num+1,0);
        for(int i=1;i<=num;i++){
            dp[i]=dp[i>>1]+(i&1);
        }
        return dp;
    }
};

//rightmost bits solution2, turnoff rightmost bits, then plus one
class Solution3 {
public:
    vector<int> countBits(int num) {
        if(num==0)return{0};
        vector<int> dp(num+1,0);
        for(int i=1;i<=num;i++){
            dp[i]=dp[i&(i-1)]+1;
        }
        return dp;
    }
};