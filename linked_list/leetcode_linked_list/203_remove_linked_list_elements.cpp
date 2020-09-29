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
        
        while(head&&head->val==val){
            head=head->next;
        }
        
        ListNode* res=head;
        dummy.next=res;
        
        while(head){
            if(head->next){
                if(head->next->val==val){
                    head->next=head->next->next;
                    head=head->next;
                    res=res->next;
                }else{
                    res->next=head->next;
                    
                }
            }
            if(head->next->val!=val){
                
            }
            if(head->val!=val){
                res=head;
                res=res->next;
                head=head->next;
            }else{
                head=head->next;
            }
        }
        return dummy.next;
    }
};
