//
//  476_number_complement.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


//time limit exceeded
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res=m;
        for(int i=m+1;i<=n;i++){
            res=res&i;
        }
        return res;
    }
};


//initial idea of brian kernighan's algorithm
class Solution2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0)return 0;
        int index=0;
        for(;index<=31;index++){
            if(index==31){
                break;
            }else{
                if(m<(1<<index))break;
            }
        }

        int res=m;
        // cout<<index<<endl;
        if(index!=31&&(1<<index<=n)){
            return 0;
        }
        int u=index==31?INT_MAX:1<<index;
        // cout<<m<<" "<<u<<" "<<n<<endl;
        for(int i=m;i<min(u,n);i++){
            res=res&i;
            if(res==0)return 0;
        }
        res=res&min(u,n);
        return res;
    }
};

//bit shift solution
//for example 1111001(n)
//            1110010(m)
// then all numbers from 0010 to 1001 will be 0 after AND operation
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m!=n){
            m=m>>1;
            n=n>>1;
            i++;
        }
        return m<<i;
    }
};

//brian kernighan's algorithm
//https://stackoverflow.com/questions/12383002/please-explain-the-logic-behind-kernighans-bit-counting-algorithm
//x=n&(n-1)=n&(n-1)&(n-2)&...&(x+1)&x
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m<n){
            n=n&(n-1);
        }
        return n;
    }
};
