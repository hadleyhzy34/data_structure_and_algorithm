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
    //delete numbers that are duplicated
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return nullptr;
        
        //previous node of previous node
        ListNode* pre_pre=nullptr;
        //previous node of current node
        ListNode* pre_cur=nullptr;
        //current node
        ListNode* cur=head;
        
        //final first node for output
        ListNode* res=new ListNode;
        ListNode dummy(0);
        dummy.next=res;
        
        while(cur){
            if(pre_cur){
                if(pre_pre){     //when it loops to at least more than three nodes
                    if(pre_cur->val!=pre_pre->val&&pre_cur->val!=cur->val){
                        res->next=pre_cur;
                        res=res->next;
                    }
                }else{           //pre_per is not assigned yet
                    if(pre_cur->val!=cur->val){
                        res->next=pre_cur;
                        res=res->next;
                    }
                }                 //move all three nodes forward
                pre_pre=pre_cur;
                pre_cur=cur;
                cur=cur->next;
            }else{
                pre_cur=cur;
                if(!cur->next){  //if there's only one node
                    res->next=cur;
                    res=res->next;
                }
                cur=cur->next;
            }
        }

        if(pre_cur&&pre_pre){       //check last node where cur node is nullptr
            if(pre_cur->val!=pre_pre->val){
                res->next=pre_cur;
                res=res->next;
            }
        }
        res->next=nullptr;
        return dummy.next->next;
    }
};

class Solution2 {
public:
    //delete numbers that are duplicated
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return nullptr;
        ListNode * dummy = new ListNode;
        dummy->next=head;
        ListNode *pre=dummy, *cur=head, *next=head->next;
        
        bool flag=false;
        while(next){
            if(cur->val!=next->val){
                //if cur->val==pre->val
                if(flag){
                    pre->next=next;
                    cur=next;
                    next=next->next;
                }else{  // not duplicated
                    pre=pre->next;
                    cur=cur->next;
                    next=next->next;
                }
                flag=false;
            }else{
                flag=true;
                next=next->next;
            }
        }
        
        //
        if(flag)pre->next=nullptr;
        return dummy->next;
    }
};

class Solution3 {
public:
    //delete numbers that are duplicated
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return nullptr;
        ListNode dummy(0);
        dummy.next=head;
        ListNode *candidate=&dummy, *cur=head, *next=head->next;
        
        //flag to check if cur contains duplicated value or not
        bool flag=false;
        while(next){
            if(next->val!=cur->val){
                //if curent node is not duplicated and next node is not same as cur node, then cur node is one for final output
                if(!flag){
                    candidate->next=cur;
                    candidate=cur;
                    cur=next;
                    next=next->next;
                }else{//if current node is duplicated one
                    cur=next;
                    next=next->next;
                }
                flag=false;
            }else{
                flag=true;
                //keep cur node, move next node to next node, in the future to compare with this duplicated cur node
                next=next->next;
            }
        }
        
        return dummy.next;
    }
};

