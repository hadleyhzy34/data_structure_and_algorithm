//
//  537_complex_number_multiplcation.cpp
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
    string complexNumberMultiply(string a, string b) {
        vector<int> number1{0,0,1,1},number2{0,0,1,1};
        int i=0;
        while(i<a.length()){
            while(a[i]!='+'){
                if(a[i]=='-'){
                    number1[2]=-1;
                    i++;
                    continue;
                }
                int j=(int)(a[i]-'0');
                number1[0]=number1[0]*10+j;
                i++;
            }
            i++;
            while(a[i]!='i'){
                if(a[i]=='-'){
                    number1[3]=-1;
                    i++;
                    continue;
                }
                int j=(int)(a[i]-'0');
                number1[1]=number1[1]*10+j;
                i++;
            }
            i++;
        }
        cout<<number1[0]<<" "<<number1[1]<<endl;
        
        i=0;
        while(i<b.length()){
            while(b[i]!='+'){
                if(b[i]=='-'){
                    number2[2]=-1;
                    i++;
                    continue;
                }
                int j=(int)(b[i]-'0');
                number2[0]=number2[0]*10+j;
                i++;
            }
            i++;
            while(b[i]!='i'){
                if(b[i]=='-'){
                    number2[3]=-1;
                    i++;
                    continue;
                }
                int j=(int)(b[i]-'0');
                number2[1]=number2[1]*10+j;
                i++;
            }
            i++;
        }
        
        cout<<number2[0]<<" "<<number2[1]<<endl;
        
        string res;
        int real=number1[0]*number2[0]*number1[2]*number2[2]-number1[1]*number2[1]*number1[3]*number2[3];
        res.append(to_string(real));
        
        res.append("+");
        int vir=number1[0]*number1[2]*number2[1]*number2[3]+number1[1]*number1[3]*number2[0]*number2[2];
        res.append(to_string(vir));
        res.append("i");
        return res;
    }
};
