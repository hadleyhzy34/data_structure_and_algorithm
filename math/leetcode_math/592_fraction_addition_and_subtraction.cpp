//
//  592_fraction_addition_and_subtraction.cpp
//  leetcode_math
//
//  Created by Hadley on 13.08.20.
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
    int gcd(int a,int b){
        while(a!=0){
            int t=a;
            a=b%a;
            b=t;
        }
        if(b<0){
            return -b;
        }
        return b;
    }
    string fractionAddition(string expression) {
        vector<long>n;
        
        bool sig=true;
        for(int i=0;i<expression.length();i++){
            if(expression[i]=='-'){
                sig=false;
                continue;
            }else if(expression[i]=='+'){
                sig=true;
                continue;
            }
            if(isdigit(expression[i])){
                if(i<expression.length()-1&&isdigit(expression[i+1])){
                    n.push_back((sig==true)?10:-10);
                    i++;
                }else{
                    n.push_back((sig==true)?expression[i]-'0':-(expression[i]-'0'));
                    cout<<sig<<" "<<n.size()<<" "<<n[n.size()-1]<<endl;
                }
            }
            if(expression[i]=='/'){
                sig=true;
                continue;
            }
        }
        
        for(auto x:n){
            cout<<x<<" ";
        }
        cout<<endl;
        
        vector<long>res;
        for(int i=0;i<n.size();i++){
            if(res.empty()){
                res.push_back(n[0]);
                res.push_back(n[1]);
                i++;
            }else if(i&1){
                res[1]=res[1]*n[i];
            }else{
                res[0]=res[0]*n[i+1]+res[1]*n[i];
            }
            cout<<res[0]<<" "<<res[1]<<endl;
        }
        
        string s;
        if(res[0]==0){
            s.append("0/1");
            return s;
        }
        int g=gcd(res[0],res[1]);
        cout<<g<<" gcd"<<endl;
        res[0]=res[0]/g;
        res[1]=res[1]/g;
        cout<<res[0]<<" "<<res[1]<<endl;
        s.append(to_string(res[0]));
        s.append("/");
        s.append(to_string(res[1]));
        return s;
    }
};
