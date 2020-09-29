//
//  91_decode_ways.cpp
//  string
//
//  Created by Hadley on 22.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int one[s.size()];
        int two[s.size()];

        if(s[0]-'0'==0){
            return 0;
        }else{
            one[0]=1;
            two[0]=0;
        }
        
        for(int i=1;i<s.size();i++){
            if(s[i]-'0'==0){
                if(s[i-1]-'0'<=2&&s[i-1]-'0'>0){
                    one[i]=0;
                    two[i]=one[i-1];
                }else{
                    return 0;
                }
            }else{
                if(stoi(s.substr(i-1,2))<=26&&stoi(s.substr(i-1,2))>10){
                    one[i]=one[i-1]+two[i-1];
                    two[i]=one[i-1];
                }else{
                    one[i]=one[i-1]+two[i-1];
                    two[i]=0;
                }
            }
        }
        return one[s.length()-1]+two[s.length()-1];
    }
};
