//
//  143_reorder_list.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 06.10.20.
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
    void reorderList(ListNode* head) {
        vector<ListNode*> node;

        ListNode* temp=head;
        while(temp){
            node.push_back(temp);
            temp=temp->next;
        }
        
        int n=node.size();
        for(int i=0;i<node.size()/2;i++){
            node[i]->next=node[n-1-i];
            node[n-1-i]->next=node[i+1];
        }

    }
};

class Solution2 {
public:
    void reorderList(ListNode* head) {
        if(!head)return;
        stack<ListNode*> node;

        ListNode* temp=head;
        while(temp){
            node.push(temp);
            temp=temp->next;
        }
        
        int n=node.size();
        ListNode* ptr=head;
        for(int i=0;i<n/2;i++){
            // cout<<i<<" "<<node.top()->val<<" "<<node.size()<<endl;
            ListNode *element = node.top();
            node.pop();
            element->next=ptr->next;
            ptr->next=element;
            ptr=ptr->next->next;
        }
        ptr->next=nullptr;
    }
};
