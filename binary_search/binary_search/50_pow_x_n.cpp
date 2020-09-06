//
//  50_pow_x_n.cpp
//  binary_search
//
//  Created by Hadley on 08.08.20.
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
    double myPow(double x, int n) {
        if(n==0||x==1)return 1;
        double r=(n>0)?x:1/x;
        double res=r;
        long long temp=(long(n)>0)?long(n):-long(n);
        // temp=(temp>0)?temp:-temp;
        
        
        //pow(x,n)=x^(((1*2+1)*2+1)*2+1)*2+1)......)
        int count=0;
        stack<int> beta;
        while(temp!=1){
            beta.push(temp&1);
            count++;
            temp/=2;
            // cout<<temp<<" "<<count<<endl;
        }
        cout<<"count is: "<<count<<endl;
        
        for(int i=1;i<=count;i++){
            res=res*res;
            if(beta.top()==1)res*=r;
            beta.pop();
        }
        
        return res;
    }
};
