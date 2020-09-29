//
//  83_remove_duplicates_from_sorted_list.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include "83_Remove_duplicats_from_sorted_list.cpp"
using namespace std;

class Solution {
public:
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp=head;
        //        if(head){
        //            head=head->next;
        //        }
        if(!head)return NULL;
        while (head) {
            if(head->next&&head->next->val==head->val){
                head->next=head->next->next;
            }else{
                head=head->next;
            }
        }
        return temp;
    }
};
