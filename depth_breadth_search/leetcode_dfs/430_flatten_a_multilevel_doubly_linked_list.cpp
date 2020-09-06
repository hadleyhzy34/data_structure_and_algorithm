//
//  430_flatten_a_multilevel_doubly_linked_list.cpp
//  leetcode_dfs
//
//  Created by Hadley on 27.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
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
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flat(Node* head){
        if(!head)return nullptr;
        
        Node* ori_next=flat(head->next);
        Node* ori_child=flat(head->child);
        
        Node* pointer=head;
        
        if(ori_child){
            pointer->next=ori_child;
            while(pointer->next){
                pointer->next->prev=pointer;
                pointer->child=nullptr;
                pointer=pointer->next;
            }
        }
        
        pointer->next=ori_next;
        if(ori_next){
            ori_next->prev=pointer;
        }
        return head;
    }
        
//        flat(head->next);
//
//
//
//
//        if(head->next){
//            if(head->child){
//                Node* temp=head->next;
//                head->next=head->child;
//                head->next->prev=head;
//                head->child=nullptr;
//                flat(head->next)->next=temp;
//                temp->prev=flat(head->next);
//                return flat(temp);
//            }else{
//                return flat(head->next);
//            }
//        }else{
//            return head;
//        }
//
//    }
    Node* flatten(Node* head) {
        Node* temp = new Node();
        temp->val=0;
        temp->child=nullptr;
        temp->prev=nullptr;
        temp->next=head;
        head->prev=temp;
        
        flat(head);
        return temp->next;
    }
};
