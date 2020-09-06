//
//  83_Remove_duplicats_from_sorted_list.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 14.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

#ifndef _ListNode
#define _ListNode

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //create a dummy pointer that is used for return to first node of linked list
        ListNode dummy{0};
        //pointer to dummy node, but it's address is changed during while loop
        ListNode *temp = &dummy;
        while(head){
            //if current node data is not equal to next node data meanwhile next node is not null, then make temp pointer ->next points to current node and change current point to be this node
            if(head->next&&head->val!=head->next->val){
                temp->next = head;
                temp = temp->next;
            }
            head=head->next;
        }
        return dummy.next;
    }
};

#endif
