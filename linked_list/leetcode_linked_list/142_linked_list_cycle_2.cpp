//
//  142_linked_list_cycle_2.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 06.10.20.
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

class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>map;
        ListNode *temp=head;
        while(temp){
            if(map.find(temp)!=map.end()){
                return temp;
            }else{
                map.insert(temp);
                temp=temp->next;
            }
        }
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return nullptr;
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        
        while(slow!=fast){
            if(!slow->next||!fast->next||!fast->next->next)return nullptr;
            slow=slow->next;
            fast=fast->next->next;
        }
        // cout<<slow->val<<" "<<fast->val<<endl;
        
        ListNode *temp = head;
        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
        }

        return slow;
    }
};
