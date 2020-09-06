//
//  206_reverse_linked_list.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 15.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "83_Remove_duplicats_from_sorted_list.cpp"
#include <string>
#include <iostream>
using namespace std;

class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* reversed = NULL;
        while(head){
            ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = head->val;
            temp->next = reversed;
            reversed = temp;
            head=head->next;
            
        }
        return reversed;
    }
};

class Solution206_1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reversed = NULL;
        ListNode* temp = head;
        ListNode* next = NULL;
        while(temp){
            //this step is the key issue, if not assigned temp->next to another 'container', since head is assigned to temp, any changes to temp will affect head, so assigning reversed to temp->next will make current head to point to reversed instead of real next node
            next = temp->next;
            temp->next = reversed;
            //change address of reverse to make reverse also points to current head
            reversed = temp;
            
            temp = next;
            }
//        cout<<dummy.next->val<<endl;
        return reversed;
        }
};

//class Solution206_2 {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode *reversed = NULL;
//        cout<<&dummy<<endl;
//        ListNode* temp = head;
//        ListNode* next = NULL;
//        while(temp){
//            //this step is the key issue, if not assigned temp->next to another 'container', since head is assigned to temp, any changes to temp will affect head, so assigning reversed to temp->next will make current head to point to reversed instead of real next node
//            next = temp->next;
//            temp->next = reversed;
//            //change address of reverse to make reverse also points to current head
//            reversed = temp;
//            cout<<reversed<<endl;
//            temp = next;
//            }
////        cout<<dummy.next->val<<endl;
//        return reversed;
//        }
//};
//
