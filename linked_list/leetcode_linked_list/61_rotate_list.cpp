//
//  61_rotate_list.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 03.10.20.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        vector<ListNode*>res;
        while(head){
            res.push_back(head);
            head=head->next;
        }
        k=k%res.size();
        reverse(res.begin(),res.begin()+res.size()-k);
        reverse(res.end()-k,res.end());
        reverse(res.begin(), res.end());
        
        ListNode* r=res[0];
        int index=0;
        while(index<res.size()-1){
            res[index]->next=res[index+1];
            index++;
        }
        res[index]->next=nullptr;
        return r;
    }
};

class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        int cnt=0;
        
        ListNode* left=head;
        ListNode* right=new ListNode;
        ListNode* temp=head;
        
        while(head){
            cnt++;
            if(!head->next){
                right=head;
            }
            head=head->next;
        }
        k=k%cnt;
        if(k==0)return left;

        right->next=left;
        
        ListNode* last=new ListNode;

        ListNode* res;
        int i=0;
        while(i<cnt){
            //last node
            if(i==cnt-1-k){
                last=temp;
            }else if(i==cnt-k){//first node
                res=temp;
            }
            temp=temp->next;
            i++;
        }
        last->next=nullptr;
        
        return res;
    }
};
