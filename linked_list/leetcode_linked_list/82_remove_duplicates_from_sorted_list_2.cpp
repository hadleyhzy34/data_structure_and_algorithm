//
//  82_remove_duplicates_from_sorted_list_2.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 04.10.20.
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

class Solution {
public:
    //delete duplicated numbers
//    ListNode* deleteDuplicates(ListNode* head) {
//        ListNode* cur=head;
//        ListNode* pre=head;
//        while(cur){
//            if(cur->val==pre->val){
//                cur=cur->next;
//            }else{
//                pre->next=cur;
//                pre=cur;
//                cur=cur->next;
//            }
//        }
//        pre->next=nullptr;
//        return head;
//    }
    
    //delete numbers that are duplicated
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res=nullptr;
        if(!head)return nullptr;
        
        //previous node of previous node
        ListNode* pre_pre=nullptr;
        //previous node of current node
        ListNode* pre_cur=nullptr;
        //current node
        ListNode* cur=nullptr;
        
        
        if(head->next){
            if(head->val!=head->next->val){
                res=head;
            }
            pre_pre=head;
            pre_cur=head->next;
        }else{
            return head;
        }
        
        if(head->next->next){
            cur=head->next->next;
        }else{
            return res;
        }
        
        while(cur){
            if(pre_cur->val!=pre_pre->val&&pre_cur->val!=cur->val){
                if(res){
                    head->next=pre_cur;
                    head=head->next;
                }else{
                    res=pre_cur;
                }
            }
            pre_pre=pre_cur;
            pre_cur=cur;
            cur=cur->next;
        }
        if(pre_cur->val!=pre_pre->val){
            head->next=pre_cur;
        }
        return res;
    }
};
