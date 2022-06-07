//
//  142_linked_list_cycle_2.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 14.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return nullptr;
        ListNode *t=head->next;
        ListNode *h=head->next->next;
        while(t!=h){
            if(!t->next||!h->next||!h->next->next)return nullptr;
            t=t->next;
            h=h->next->next;
        }
        ListNode * t1=head;
        while(t1!=h){
            t1=t1->next;
            h=h->next;
        }
        return t1;
    }
};
