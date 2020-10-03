//
//  459_repeated_substring_pattern.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int m=s.size();
        for(int i=1;i<=m/2;i++){
            if(m%i==0){
                string temp;
                int n=m/i;
                while(n--){
                    temp+=s.substr(0,i);
                }
                if(temp==s)return true;
            }
        }
        return false;
    }
};

//solution2:https://leetcode.com/problems/repeated-substring-pattern/discuss/826135/C%2B%2B-O(N)-time-or-One-liner-without-KMP-Explained-or-Beats-99


//ababa
class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        // Construct partial match table (lookup table).
        // It stores the length of the proper prefix that is also a proper suffix.
        // ex. ababa --> [0, 0, 1, 2, 1]
        // ab --> the length of common prefix / suffix = 0
        // aba --> the length of common prefix / suffix = 1
        // abab --> the length of common prefix / suffix = 2
        // ababa --> the length of common prefix / suffix = 1
        for (int i = 1; i < n; ++i) {
            //length of common prefix/suffix of previous one
            int j = dp[i - 1];
            //s[j-1+1], index of first char after common prefix/suffix
            while (j > 0 && s[i] != s[j]) {
                //if it doesn't match, then jump to common prefix of the first common prefix which is equal to last common suffix of the last common suffix
                j = dp[j - 1];
            }
            if (s[i] == s[(j-1)+1]) {
                ++j;
            }
            //current common prefix/suffix length
            dp[i] = j;
        }

        int l = dp[n - 1];
        // check if it's repeated pattern string
        return l != 0 && l % (n - l) == 0;
    }
};

vector<int> kps(string s){
    int n=s.length();
    vector<int>dp(n,0);
    //index to loop through string s
    int i=1;
    //current length of lps
    int len=0;
    while(i<n){
        len=dp[i-1];
        if(s[i]==s[len-1+1]){
            len++;
            i++;
            dp[i]=len;
        }else if(len>0){
            //jump to length of the common prefix of the common prefix
            len=dp[len-1];
        }else{
            dp[i]=0;
            i++;
        }
    }
    return dp;
}
