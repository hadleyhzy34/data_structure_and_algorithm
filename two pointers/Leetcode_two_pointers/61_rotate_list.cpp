//
//  61_rotate_list.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 14.08.20.
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
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0)return head;
        ListNode* t1=new ListNode(0);
        ListNode* t2=new ListNode(0);
        ListNode* t3=head;
        int L=0;
        while(t3){
            L++;
            t3=t3->next;
        }
        if(k%L==0)return head;
        ListNode & dummy=*t1;
        t1->next=head;
        t2->next=head;
        int c1=0,c2=0,kk=k%L;
        while(t1){
            if(c2-c1>=kk){
                t1=t1->next;
                if(t1)c1++;
            }
            // cout<<c1<<" "<<t1->val<<" "<<c2<<" "<<t2->val<<endl;
            t2=t2->next;
            if(t2)c2++;
            
            cout<<c1<<" "<<c2<<endl;
            if(!t2->next&&c1+kk==c2){
                cout<<c1<<" "<<c2<<" "<<t1->val<<endl;
                ListNode* res=t1->next;
                t1->next=NULL;
                t2->next=dummy.next;
                return res;
            }
        }
        return dummy.next;
    }
};
