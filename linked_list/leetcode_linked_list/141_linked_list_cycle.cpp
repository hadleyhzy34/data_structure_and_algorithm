//
//  141_linked_list_cycle.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 14.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include "83_Remove_duplicats_from_sorted_list.cpp"
using namespace std;


//o(n) space
class Solution141 {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> s;
        while(head){
            if(s.find(head)!=s.end()){
                return true;
            }
            s.insert(head);
            head=head->next;
        }
        return false;
    }
};

//o(1) space
class Solution141_1 {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        while(fastPtr&&fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
//            cout<<slowPtr->val<<" "<<fastPtr->val<<endl;
            if(slowPtr==fastPtr){
                return true;
            }
        }
        return false;
    }
};
