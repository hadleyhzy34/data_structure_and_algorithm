//
//  204_count_primes.cpp
//  leetcode_math
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
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<int> prime{2};
        for(int i=3;i<n;i+=2){
            bool p=true;;
            for(auto x:prime){
                if(i%x==0){
                    p=false;
                    break;
                }
            }
            if(p){
                // cout<<i<<endl;
                prime.push_back(i);
            }
        }
        return prime.size();
    }
};

class Solution2 {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<int> prime{2};
        int lPrime=2;
        while(lPrime<=n){
            
        }
        for(int i=3;i<n;i+=2){
            bool p=true;;
            for(auto x:prime){
                if(i%x==0){
                    p=false;
                    break;
                }
            }
            if(p){
                // cout<<i<<endl;
                prime.push_back(i);
            }
        }
        return prime.size();
    }
};
