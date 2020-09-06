//
//  509_fibonacci_number.cpp
//  leetcode_array
//
//  Created by Hadley on 20.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fib(int N) {
        vector<int> fib;
        fib.push_back(0);
        fib.push_back(1);
        if(N<=1){
            return fib[N];
        }
        for(int i=2;i<=N;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        return fib[N];
    }
};

class Solution2 {
public:
    int fib(int N) {
        if(N==0)return 0;
        if(N==1)return 1;
        return fib(N-1)+fib(N-2);
    }
};
