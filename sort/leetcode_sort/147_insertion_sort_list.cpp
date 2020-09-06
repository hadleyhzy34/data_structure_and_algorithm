//
//  130_surrounded_regions.cpp
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
        ListNode * sortNode=new Node(head->val);
        ListNode *temp=NULL;
        while(head->next){
            temp=head->next;
        }
    }
};
