//
//  92_reverse_linked_list_2.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 04.10.20.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next=head;
        int cnt=1;
        //mark left node of m position node if m!=1
        ListNode* left=new ListNode;
        stack<ListNode*>s;
        while(head){
            if(cnt>n)break;
            if(cnt==m-1){
                left=head;
            }
            if(cnt>=m&&cnt<=n){
                s.push(head);
            }
            head=head->next;
            cnt++;
        }
        
        //mark first node if m==1
        ListNode* res=new ListNode;
        if(m==1)res=s.top();
        while(!s.empty()){
            left->next=s.top();
            left=left->next;
            s.pop();
        }
        left->next=head;
        return m==1? res:dummy.next;
    }
};
