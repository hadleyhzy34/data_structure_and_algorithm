//
//  482_license_key_formatting.cpp
//  string
//
//  Created by Hadley on 01.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string temp;
        for(auto &s:S){
            if(s!='-'){
                temp+=toupper(s);
            }
        }
        string res;
        for(int j=temp.size()-1;j>=0;j--){
            if(j-K+1>0){
                res="-"+temp.substr(j-K+1,K)+res;
            }else{
                res=temp.substr(0,j+1)+res;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        for(auto it=S.rbegin();it!=S.rend();it++){
            if(*it!='-'){
                if(res.size()%(K+1)==K)res='-'+res;
                res=(char)(toupper(*it))+res;
            }
        }
        
        return res;
    }
};
