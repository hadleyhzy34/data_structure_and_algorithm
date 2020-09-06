//
//  2_add_two_numbers.cpp
//  leetcode_math
//
//  Created by Hadley on 12.08.20.
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
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long a=0;
        long long b=0;
        int count=0;
        while(l1){
            a+=l1->val*pow(10, count);
            l1=l1->next;
            count++;
        }
        
        count=0;
        while(l2){
            b+=l2->val*pow(10, count);
            l2=l2->next;
            count++;
        }
        
        long long c=a+b;
        
        cout<<a<<" "<<b<<" "<<c<<endl;
        ListNode* res = new ListNode();
        ListNode* temp = res;
        while(c!=0){
            temp->val=c%10;
            c=c/10;
            if(c!=0){
                temp->next=new ListNode();
                temp=temp->next;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>a;
        vector<int>b;
        
        while(l1){
            a.push_back(l1->val);
            l1=l1->next;
        }

        while(l2){
            b.push_back(l2->val);
            l2=l2->next;
        }
        
        vector<int>c(max(a.size(),b.size()));
        int count=0;
        for(int i=0;i<c.size();i++){
            if(i>=a.size()){
                c[i]=(b[i]+count)%10;
                count=(b[i]+count)/10;
            }else if(i>=b.size()){
                c[i]=(a[i]+count)%10;
                count=(a[i]+count)/10;
            }else{
                c[i]=(a[i]+b[i]+count)%10;
                count=(a[i]+b[i]+count)/10;
            }
        }
        if(count>0)c.push_back(count);
        
        for(auto x:c){
            cout<<x<<" ";
        }
        
        ListNode* res = new ListNode();
        ListNode* temp = res;
        for(int i=0;i<c.size()-1;i++){
            temp->val=c[i];
            temp->next=new ListNode();
            temp=temp->next;
        }
        temp->val=c[c.size()-1];
        return res;
    }
};
