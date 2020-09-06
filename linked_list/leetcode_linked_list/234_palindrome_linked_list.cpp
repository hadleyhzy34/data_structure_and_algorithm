//
//  234_palindrome_linked_list.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 15.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "83_Remove_duplicats_from_sorted_list.cpp"
#include <iostream>
using namespace std;

class Solution234 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode dummy{0};
        dummy.next = head;
        ListNode *first = dummy.next;
        cout<<"first value is "<<first->val<<endl;
        cout<<"next first value is "<<first->next->val<<endl;
        cout<<"next first value is "<<first->next->next->val<<endl;
        
        ListNode *reversed = NULL;
        ListNode* temp = head;
        ListNode* next = NULL;
        while(temp){
            cout<<"first value is "<<first->val<<endl;
            cout<<"next first value is "<<first->next->val<<endl;
            cout<<"next first value is "<<first->next->next->val<<endl;
            next = temp->next;
            temp->next = reversed;
            reversed = temp;
            temp = next;
        }
        
        while(reversed&&first){
            cout<<"reversed value is "<<reversed->val<<endl;
            cout<<"first value is "<<first->val<<endl;
            if(reversed->val!=first->val){
                return false;
            }
            reversed = reversed->next;
            first = first->next;
            cout<<"reversed value is "<<reversed->val<<endl;
            cout<<"first value is "<<first->val<<endl;
        }
        return true;
    }
};
