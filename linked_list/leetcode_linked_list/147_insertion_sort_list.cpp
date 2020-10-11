//
//  147_insertion_sort_list.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 07.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//
#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return nullptr;
        vector<ListNode*>res;
        ListNode* temp=head;
        
        //build vector
        while(temp){
            res.push_back(temp);
            temp=temp->next;
        }
        
        //sort vector
        for(int i=1;i<res.size();i++){
            int key=i;
            for(int j=i-1;j>=0;j--){
                if(res[j]->val<res[key]->val){
                    break;
                }else{
                    swap(res[j], res[key]);
                    key=j;
                }
            }
        }
        
        //rebuld linked list
        for(int i=0;i<res.size()-1;i++){
            res[i]->next=res[i+1];
        }
        res[res.size()-1]->next=nullptr;
        return res[0];
    }
};


class Solution2 {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return nullptr;
        ListNode * dummy=new ListNode;
        dummy->next = head;
        
        ListNode *pre=dummy, *cur=head;
        
        while(cur){
            if(cur->next&&cur->next->val<cur->val){
                while (pre->next&&pre->next->val<cur->next->val) {
                    pre=pre->next;
                }
                ListNode* temp=pre->next;
                pre->next=cur->next;
                cur->next=cur->next->next;
                pre->next->next=temp;
                pre=dummy;
            }else{
                cur=cur->next;
            }
        }
        return dummy->next;
    }
};
