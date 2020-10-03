//
//  19_remove_nth_node_from_end_of_list.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*>res;
        ListNode* cur=head;
        while(cur){
            res.push_back(cur);
            cur=cur->next;
        }
        int size=res.size();
        if(n==1){
            res[size-1-n+1-1]->next=nullptr;
        }else{
            res[size-1-n+1-1]->next=res[size-1-n+1+1];
        }
        return head;
    }
};
