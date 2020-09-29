//
//  415_add_strings.cpp
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
    string addStrings(string num1, string num2) {
        int s1=0,s2=0;
        for(auto &x:num1){
            s1=s1*10+x-'0';
        }
        
        for(auto &x:num2){
            s2=s2*10+x-'0';
        }
        
        int s3=s1+s2;
        if(s3==0)return "0";
        string res="";
        cout<<s3<<endl;
        while(s3){
            string temp;
            cout<<s3<<" "<<s3%10<<" "<<s3%10+'0';
            temp.push_back(s3%10+'0');
            res=temp+res;
            cout<<temp<<" "<<res<<endl;
            s3=s3/10;
        }
        return res;
    }
};

class Solution2 {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int count=0;
        string res;
        for(int i=0;i<max(num1.size(),num2.size());i++){
            if(i>=num1.size()){
                int temp=+num2[i]-'0'+count;
                res.push_back(temp%10+'0');
                count=temp/10;
            }else if(i>=num2.size()){
                int temp=num1[i]-'0'+count;
                res.push_back(temp%10+'0');
                count=temp/10;
            }else{
                int temp=num1[i]-'0'+num2[i]-'0'+count;
                res.push_back(temp%10+'0');
                count=temp/10;
            }
        }
        if(count)res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
