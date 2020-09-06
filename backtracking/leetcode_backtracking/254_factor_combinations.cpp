//
//  254_factor_combinations.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 22.08.20.
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
    void factors(int n,int j,vector<int>&subset,bool prime,vector<vector<int>>&res){
        for(int i=j;i<=sqrt(n);i++){
            if(n%i!=0)continue;
            prime=false;
            subset.push_back(i);
            subset.push_back(n/i);
            res.push_back(subset);
            subset.pop_back();
            factors(n/i,i,subset,true,res);
            subset.pop_back();
        }
        if(prime==true&&!subset.empty()){
            // res.push_back(subset);
            return;
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        if(n<=1)return {};
        vector<int>subset;
        vector<vector<int>>res;
        factors(n, 2,subset, true, res);
        return res;
    }
};

class Solution2 {
public:
    
    void factors(int n,vector<int>&subset,bool prime,vector<vector<int>>&res){
        for(int i=2;i<n;i++){
            if(n%i!=0)continue;
            prime=false;
            subset.push_back(i);
            subset.push_back(n/i);
            vector<int> temp=subset;
            sort(temp.begin(),temp.end());
            if(find(res.begin(), res.end(), temp)==res.end()){
                // cout<<n<<" "<<i<<" "<<n/i<<endl;
                // cout<<"subset is: ";
                // for(auto x:temp)cout<<x<<" ";
                // cout<<endl;
                res.push_back(temp);
            }
            subset.pop_back();
            factors(n/i,subset,true,res);
            subset.pop_back();
        }
        if(prime==true&&!subset.empty()){
            // res.push_back(subset);
            return;
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        if(n<=1)return {};
        vector<int>subset;
        vector<vector<int>>res;
        factors(n, subset, true, res);
        return res;
    }
};


class Solution3 {
public:
    bool isPrime(int n)
    {
        // Corner cases
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
      
        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n % 2 == 0 || n % 3 == 0)
            return false;
      
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
      
        return true;
    }
    
    void factors(int n,int j,vector<int>&subset,vector<vector<int>>&res){
        if(isPrime(n)){
            return;
        }
        for(int i=j;i<=sqrt(n);i++){
            if(n%i!=0)continue;
            subset.push_back(i);
            subset.push_back(n/i);
            res.push_back(subset);
            subset.pop_back();
            factors(n/i,i,subset,res);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        if(n<=1)return {};
        vector<int>subset;
        vector<vector<int>>res;
        factors(n, 2,subset, res);
        return res;
    }
};
