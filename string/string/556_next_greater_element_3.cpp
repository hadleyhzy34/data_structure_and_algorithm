//
//  556_next_greater_element_3.cpp
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
    int nextGreaterElement(int n) {
        string temp;
        if(n==0)return -1;
        while(n){
            char t=n%10+'0';
            temp=t+temp;
            n=n/10;
        }
        string temp2=temp;
        sort(temp2.begin(), temp2.end(),greater<int>());
        if(temp==temp2){
            return -1;
        }else{
            return stoi(temp2);
        }
    }
};

class Solution2 {
public:
    int nextGreaterElement(int n) {
        if(n<10)return -1;
        vector<int>a;
        while(n){
            a.push_back(n%10);
            n/=10;
        }
        
        for(int i=0;i<a.size()-1;i++){
            if(a[i]>a[i+1]){
                char t=a[i];
                int count=i;
                for(int j=0;j<i+1;j++){
                    if(a[j]>a[i+1]&&a[j]<t){
                        t=a[j];
                        count=j;
                    }
                }
                swap(a[count], a[i+1]);
                sort(a.begin(), a.begin()+i+1,greater<int>());
                reverse(a.begin(), a.end());
                long long int sum=0;
                for(int j=0;j<a.size();j++){
                    sum=sum*10+a[j];
                    if(sum>INT_MAX)return -1;
                }
                return sum;
            }
        }
        return -1;
    }
};
