//
//  159_longest_substring_with_at_most_two_distinct_characters.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 18.08.20.
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

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())return 0;
        unordered_map<char, int>map;
        int maxLength=0,count=0,dis1=0,dis2=0;
        for(int i=0;i<s.length();i++){
            if((map.find(s[i])!=map.end()&&map[s[i]]<dis1)||map.find(s[i])==map.end()){
                if(count==2){
                    maxLength=max(maxLength,(i-1)-dis1+1);
                    // cout<<i<<" "<<dis1<<" "<<dis2<<" "<<(i-1)-dis1+1<<endl;
                    dis1=min(map[s[dis1]],map[s[dis2]])+1;
                    dis2=i;
                }else{
                    count++;
                    dis1=dis2;
                    dis2=i;
                    if(count==2)maxLength=max(maxLength,i-dis1+1);
                    // cout<<i<<" "<<dis1<<" "<<dis2<<" "<<i-dis1+1<<endl;
                }
            }
            map[s[i]]=i;
        }
        if(count==1){
            return s.length();
        }else{
            return max(maxLength,(int)s.length()-dis1);
        }
    }
};
