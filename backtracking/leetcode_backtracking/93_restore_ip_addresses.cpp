//
//  93_restore_ip_addresses.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 24.08.20.
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
#include <map>
using namespace std;

//class Solution {
//public:
//    void resIpAddress(string s, int l, string subset, vector<string>&res){
//        if(subset.size()==4&&l==s.length()){
//            res.push_back(subset);
//            return;
//        }else if(subset.size()!=4&&l>=s.length()){
//            return;
//        }else if(subset.size()>4&&l<=s.length()){
//            return;
//        }
//        for(int i=l;i<s.length();i++){
//            int a,b,c;
//            
//            subset.push_back(s[l]);
//            resIpAddress(s, l+1, subset,res);
//            subset.pop_back();
//
//            
//            if(l+1<s.length()){
//                b=(s[l+1]-'0')*10+s[l]-'0';
//                if(b>=10){
//                    subset.push_back(s[l]);
//                    subset.push_back(s[l+1]);
//                    resIpAddress(s, l+2, subset, res);
//                    subset.pop_back();
//                    subset.pop_back();
//                }
//            }else{
//                return;
//            }
//            
//            if(l+2<s.length()){
//                c=(s[l+2]-'0')*100+(s[l+1]-'0')*10+s[l]-'0';
//                if(c<=255&&c>=100){
//                    subset.append(s.substr(l,3));
//                    resIpAddress(s, l+3, subset, res);
//                    subset.pop_back();
//                    subset.pop_back();
//                    subset.pop_back();
//                }
//            }else{
//                return;
//            }
//            
//        }
//        
//    }
//    vector<string> restoreIpAddresses(string s) {
//        
//    }
//private:
//    vector<string>res;
//};
