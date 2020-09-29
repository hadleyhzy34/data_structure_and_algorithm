//
//  227_basic_calculator_2.cpp
//  string
//
//  Created by Hadley on 23.09.20.
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
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string>s1;
        for(int i=0;i<s.length();i++){
            string temp;
            if(s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='-'){
                temp.push_back(s[i]);
                s1.push_back(temp);
            }else{
                while(i<s.length()&&s[i]!='+'&&s[i]!='*'&&s[i]!='/'&&s[i]!='-'){
                    if(!isspace(s[i])){
                        temp.push_back(s[i]);
                    }
                    i++;
                }
                s1.push_back(temp);
                i--;
            }
        }
        
        vector<string>s2;
        for(int i=0;i<s1.size();i++){
            int m=s2.size();
            if(s1[i]=="*"){
                s2[m-1]=to_string(stoi(s2[m-1])*stoi(s1[i+1]));
                i++;
            }else if(s1[i]=="/"){
                s2[m-1]=to_string(stoi(s2[m-1])/stoi(s1[i+1]));
                i++;
            }else{
                s2.push_back(s1[i]);
            }
        }

        
        vector<string>s3;
        for(int i=0;i<s2.size();i++){
            int m=s3.size();
            if(s2[i]=="+"){
                s3[m-1]=to_string(stoi(s3[m-1])+stoi(s2[i+1]));
                i++;
            }else if(s2[i]=="-"){
                s3[m-1]=to_string(stoi(s3[m-1])-stoi(s2[i+1]));
                i++;
            }else{
                s3.push_back(s2[i]);
            }
        }
        return stoi(s3[0]);
    }
};

class Solution2 {
public:
    int calculate(string s) {
        //left number needs to * or /
        int nums;
        //left number needs to + or -
        int res=0;
        //sign means last operations of plus or minus
        int sign=1;
        //final number
        int n=0;
        //pre_op means last operation of multi or division
        char pre_op='?';
        for(int i=0;i<s.size();i++){
            if(isspace(s[i]))continue;
            if(isdigit(s[i])){
                n=10*n+(s[i]-'0');
            }else{
                if(pre_op == '*' || pre_op == '/'){
                    n = pre_op == '*' ? nums*n:nums/n;
                    pre_op = ' ';
                }
                
                if(s[i] == '*' || s[i] == '/'){
                    pre_op = s[i];
                    nums = n;
                    n = 0;
                }else{
                    res += sign*n;
                    sign = s[i]=='+' ? 1:-1;
                    n = 0;
                }
            }
        }
        if(pre_op != ' ')
            n = pre_op == '*' ? nums * n : nums / n;
        return res + sign * n;
    }
};
