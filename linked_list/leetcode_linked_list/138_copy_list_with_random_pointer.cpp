//
//  138_copy_list_with_random_pointer.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 06.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        Node *old_head = head;
        
        Node *clone_head = new Node(0);
        Node *new_head = clone_head;
        
        //map from old nodes to new nodes
        unordered_map<Node*, Node*>map;

        //deep copy old list except for random pointer
        while(old_head){
            new_head->val=old_head->val;
            if(old_head->next){
                new_head->next = new Node(0);
            }
            
            map[old_head]=new_head;
            
            old_head=old_head->next;
            new_head=new_head->next;
        }
        
        //assign random pointer
        old_head = head;
        new_head = clone_head;
        
        while(old_head&&new_head){
            if(old_head->random){
                new_head->random = map[old_head->random];
            }
            old_head=old_head->next;
            new_head=new_head->next;
        }
        return clone_head;  
    }
};
