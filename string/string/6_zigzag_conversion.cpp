//
//  6_zigzag_conversion.cpp
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
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string res="";
        int n = s.length();
        for(int i=0;i<numRows;i++){
            int count=1;
            if(i==n)break;
            res.push_back(s[i]);
            if(i==0||2*numRows-2-2*i==0){
                while(i+count*(2*numRows-2)<n){
                    res.push_back(s[i+count*(2*numRows-2)]);
                    count++;
                }
            }else{
                while(i+count*(2*numRows-2)<n||(i+count*(2*numRows-2)-2*i<n)){
                    cout<<i<<" "<<count<<" ";
                    if((i+count*(2*numRows-2)-2*i)<n){
                        res.push_back(s[i+count*(2*numRows-2)-2*i]);
                        // cout<<s[i+count*(2*numRows-2)-2*i]<<" ";
                    }
                    if(i+count*(2*numRows-2)<n){
                        res.push_back(s[i+count*(2*numRows-2)]);
                        // cout<<s[i+count*(2*numRows-2)];
                    }
                    count++;
                    cout<<endl;
                }
            }
        }
        // cout<<res.length()<<endl;
        return res;
    }
};

class Solution2 {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string res="";
        for(int i=0;i<numRows;i++){
            int c=i;
            int mask=-1;
            while(c<s.length()){
                if(c!=mask){
                  res.push_back(s[c]);
                }
                mask = 2*(numRows-1-i)+c;
                if(mask!=c&&mask<s.length()){
                    res.push_back(s[mask]);
                }
                c=2*i+mask;
            }
        }
        return res;
    }
};
