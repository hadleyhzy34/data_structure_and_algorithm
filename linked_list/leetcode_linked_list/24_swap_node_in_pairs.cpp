//
//  24_swap_node_in_pairs.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 03.10.20.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        if(head->next){
            dummy.next=head->next;
        }else{
            return head;
        }
        ListNode* pre=nullptr;
        while(head){
            ListNode* second=head->next;
            
            if(second){
                ListNode* third=second->next;
                second->next=head;
                head->next=third;
                if(pre){
                    pre->next=second;
                    pre=head;
                }
                head=head->next;
            }else{
                break;
            }
        }
        return dummy.next;
    }
};
