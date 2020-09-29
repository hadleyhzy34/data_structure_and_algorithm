//
//  21_merge_two_sorted_lists.cpp
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode(0);
        ListNode dummy(0);
        dummy.next=l3;
        while(l1&&l2){
            if(l1->val<l2->val){
                l3=l1;
                l1=l1->next;
            }else{
                l3=l2;
                l2=l2->next;
            }
            l3=l3->next;
        }
        if(l1){
            l3->next=l1;
        }else{
            l3->next=l2;
        }
        return dummy.next;
    }
};
