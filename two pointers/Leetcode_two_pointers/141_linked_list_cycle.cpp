//
//  141_linked_list_cycle.cpp
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
    bool hasCycle(ListNode *head) {
        ListNode* t=head;
        if(!t)return false;
        ListNode* h=head->next;
        if(!h)return false;
        while(t&&h){
            // cout<<t->val<<" "<<h->val<<endl;
            if(t==h){
                return true;
            }else{
                t=t->next;
                h=h->next;
                if(!h){
                    // cout<<"false is here"<<endl;
                    return false;
                }
                h=h->next;
            }
        }
        return false;
    }
};
