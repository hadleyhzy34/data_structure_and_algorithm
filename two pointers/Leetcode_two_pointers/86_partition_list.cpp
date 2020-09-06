//
//  86_partition_list.cpp
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* s=NULL,* l=NULL,* head1,* head2;
        while(head){
            if(head->val<x){
                if(!s){
                    s=head1=head;

                }else{
                    s=head;
                    s=s->next;
                }
            }else{
                if(!l){
                    l=head2=head;
                }
                l=head;
                l=l->next;
            }
            head=head->next;
        }
        
    }
};
