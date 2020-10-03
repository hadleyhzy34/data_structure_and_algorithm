//
//  415_add_strings.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 01.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i=num1.size()-1,j=num2.size()-1;
        int cnt=0;
        while(i>=0&&j>=0){
            int temp=num1[i]-'0'+num2[i]-'0'+cnt;
            cnt=temp/10;
            temp=temp%10;
            res=to_string(temp)+res;
            i--;j--;
        }
        while(i>=0){
            int temp=num1[i]-'0'+cnt;
            cnt=temp/10;
            temp=temp%10;
            res=to_string(temp)+res;
            i--;
        }
        
        while(j>=0){
            int temp=num1[j]-'0'+cnt;
            cnt=temp/10;
            temp=temp%10;
            res=to_string(temp)+res;
            j--;
        }
        return cnt==0?res:"1"+res;
    }
};
