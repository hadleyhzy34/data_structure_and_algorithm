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


class Solution2 {
public:
    int numDecodings(string s) {
                int n=s.size();
        int ones[n];
        int twos[n];


        for(int i=0;i<s.size();i++){
            if(i==0){
                if(s[i]!='0'){
                    ones[i]=1;
                    twos[i]=0;
                }else{
                    return 0;
                }
            }else if(i==1){
                if(s[i]!='0'){
                    ones[i]=ones[i-1];
                }else{
                    ones[i]=0;
                }
                if(stoi(s.substr(i-1,2))>=10&&stoi(s.substr(i-1,2))<=26){
                    twos[i]=1;
                }else{
                    twos[i]=0;
                }
            }else{
                if(s[i]!='0'){
                    ones[i]=ones[i-1]+twos[i-1];
                }else{
                    ones[i]=0;
                }
                if(stoi(s.substr(i-1,2))>=10&&stoi(s.substr(i-1,2))<=26){
                    twos[i]=twos[i-2]+ones[i-2];
                }else{
                    twos[i]=0;
                }
            }
            if(ones[i]==0&&twos[i]==0){
                return 0;
            } 
        }
        return ones[n-1]+twos[n-1];
    }
};



class Solution3 {
public:
    int numDecodings(string s) {
        int n=s.size();
        int ones[n];
        int twos[n];


        for(int i=0;i<s.size();i++){
            if(i==0){
                if(s[i]!='0'){
                    ones[i]=1;
                    twos[i]=0;
                }else{
                    return 0;
                }
            }else{
                if(s[i]!='0'){
                    ones[i]=ones[i-1]+twos[i-1];
                }else{
                    ones[i]=0;
                }
                if(stoi(s.substr(i-1,2))>=10&&stoi(s.substr(i-1,2))<=26){
                    twos[i]=ones[i-1];
                }else{
                    twos[i]=0;
                }
            }
            if(ones[i]==0&&twos[i]==0){
                return 0;
            } 
        }
        return ones[n-1]+twos[n-1];
    }
};
