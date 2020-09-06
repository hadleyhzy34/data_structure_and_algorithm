//
//  1477_insertion_sort_list.cpp
//  leetcode_sort
//
//  Created by Hadley on 09.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * sortedStart=new ListNode(head->val);
        ListNode * tempSorted=new ListNode(head->val);
        while(head->next){
            int cur=head->next->val;
            head = head->next;
            if(cur<tempSorted->val){
                sortedStart->val=cur;
                sortedStart->next=tempSorted;
                continue;
            }
            while(1){
                if(cur<tempSorted->val){
                    sortedStart->val=cur;
                    sortedStart->next=tempSorted;
                    break;
                }else{
                    tempSorted=tempSorted->next;
                }
            }
        }
    }
};
