//
//  43_multiply_strings.cpp
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
    string multiply(string num1, string num2) {
        auto n1=num1.size();
        auto n2=num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string output(n1+n2,'0');
        for(int i=0;i<n1;i++){
            int count=0;
            string res(i+n2,'0');
            for(int j=0;j<n2;j++){
                res[i+j]=(char)(((int)(num1[i]-'0')*(int)(num2[j]-'0')+count)%10+'0');
                count=((int)(num1[i]-'0')*(int)(num2[j]-'0')+count)/10;
            }
            if(count>0)res.append(to_string(count));
            count=0;
            for(int j=0;j<res.length();j++){
                output[j]=(char)(((int)(res[j]-'0')+(int)(output[j]-'0')+count)%10);
                count=((int)(res[j]-'0')+(int)(output[j]-'0')+count)/10;
            }
            if(count>0){
                if(res.length()==n1+n2){
                    output.append(to_string(count));
                }else{
                    output[res.length()]=(char)(count+'0');
                }
            }
        }
        reverse(output.begin(), output.end());
        return output;
    }
};


class Solution2 {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        vector<int> mul(m+n,0); //to store the product of num1 and num2
        string res="";//to store the result
        reverse(num1.begin(),num1.end());//reversing the string for easy calc
        reverse(num2.begin(),num2.end());
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mul[i+j]+=(num1[i]-'0')*(num2[j]-'0');
                mul[i+j+1]+=(mul[i+j])/10;//adding carry
                mul[i+j]%=10;
            }
        }
        int i;
        //removing leading zeroes if any except the last one
        for(i=m+n-1;i>0 && mul[i]==0;i--);
        
        //store the result
        for(;i>=0;i--){
            res+=to_string(mul[i]);
        }
        return res;
    }
};
