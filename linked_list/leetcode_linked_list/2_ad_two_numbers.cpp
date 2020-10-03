//
//  2_ad_two_numbers.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 02.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
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
        ListNode* res=new ListNode;
        ListNode dummy{0};
        dummy.next=res;
        
        int cnt=0;
        while(l1&&l2){
            int temp = l1->val+l2->val+cnt;
            cnt=temp/10;
            temp=temp%10;
            res->val=temp;
            
            
            l1=l1->next;
            l2=l2->next;
            if(l1&&l2){
                res->next=new ListNode;
                res=res->next;
            }
        }
        if(l1||l2){
            res->next=new ListNode;
            res=res->next;
        }
        while(l1){
            int temp=l1->val+cnt;
            cnt=temp/10;
            temp=temp%10;
            res->val=temp;
            l1=l1->next;
            if(l1){
                res->next=new ListNode;
                res=res->next;
            }
        }
        while(l2){
            int temp=l2->val+cnt;
            cnt=temp/10;
            temp=temp%10;
            res->val=temp;
            l2=l2->next;
            if(l2){
                res->next=new ListNode;
                res=res->next;
            }
        }
        if(cnt){
            res->next=new ListNode;
            res->next->val=cnt;
        }
        return dummy.next;
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode;
        ListNode dummy{0};
        dummy.next=res;
        
        int cnt=0;
        while(l1||l2){
            int temp=cnt;
            if(l1){
                temp+=l1->val;
                l1=l1->next;
            }
            if(l2){
                temp+=l2->val;
                l2=l2->next;
            }
            cnt=temp/10;
            temp=temp%10;
            res->val=temp;
            if(l1||l2){
                //1.be careful how to add new condition 2.note that how to new the next listnode
                res->next=new ListNode;
                res=res->next;
            }
        }

        if(cnt){
            res->next=new ListNode;
            res->next->val=cnt;
        }
        return dummy.next;
    }
};
