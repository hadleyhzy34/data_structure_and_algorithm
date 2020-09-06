//
//  67_add_binary.cpp
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
    string addBinary(string a, string b) {
        int m=a.length();
        int n=b.length();
        auto l=max(m,n);
        string output;
        int c=0;
        for(int i=0;i<l;i++){
            char x,y;
            if((n-i-1)>=0){
                y=b[n-i-1];
            }else{
                y='0';
            }
            if((m-i-1)>=0){
                x=a[m-i-1];
            }else{
                x='0';
            }
            // cout<<x<<"2"<<y<<" "<<i<<l<<endl;
            if(y=='1'&&x=='1'){
                char temp='0'+c;
                output=temp+output;
                c=1;
            }else if(x=='1'||y=='1'){
                if(c==1){
                    output='0'+output;
                    c=1;
                }else{
                    output='1'+output;
                    c=0;
                }
            }else{
                char temp='0'+c;
                output=temp+output;
                c=0;
            }
            // cout<<x<<" 3 "<<y<<" "<<output<<endl;
        }
        if(c)output='1'+output;
        return output;
    }
};
