//
//  21_merge_sorted_lists.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 13.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>


//Definition for singly-linked list.
struct ListNode1 {
     int val;
     ListNode1 *next;
     ListNode1(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode1* mergeTwoLists(ListNode1* l1, ListNode1* l2) {
        ListNode1 dummy{0};  //the key reason that we create a dummy non-pointer node is that after iterating, we must find a way to return the first of node of two merged sorted list, and this dummy is used for tracing the first node by setting dummy.next
        ListNode1 *temp = &dummy; //at step temp pointer points to dummy which is head of this linked list
        while(l1&&l2){
            if(l1->val>l2->val){
                temp->next = l2;
                l2=l2->next;
                
            }else{
                temp->next = l1;
                l1=l1->next;
            }
            //note that at this step, temp is no longer points to dummy since address that it points to is changed
            temp=temp->next;
        }
        temp->next = l1?l1:l2;
        return dummy.next;
        
    }
};
