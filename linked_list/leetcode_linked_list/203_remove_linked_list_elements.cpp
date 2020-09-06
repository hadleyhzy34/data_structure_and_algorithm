//
//  203_remove_linked_list_elements.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 14.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "83_Remove_duplicats_from_sorted_list.cpp"

class Solution203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy{0};
//        dummy.next = head;
        ListNode* output = &dummy;
        while(head){
            if(head->val==val){
                head=head->next;
                continue;
            }
//            std::cout<<head->val<<std::endl;
            output->next=head;
            head=head->next;
            output=output->next;
            std::cout<<output->val<<std::endl;
        }
        return dummy.next;
    }
};
