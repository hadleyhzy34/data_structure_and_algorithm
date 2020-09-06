//
//  138_copy_list_with_random_pointer.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 18.08.20.
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
#include <map>
using namespace std;


// Definition for a Node.
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
        vector<Node*> head_list;
        Node* temp=head;
        while(temp){
            head_list.push_back(temp);
            temp=temp->next;
        }
        Node* h=new Node(0);
        vector<pair<Node*, int>>map;
        Node *res1=h,*res2=h;
        while(head){
            h->val=head->val;
            if(head->next){
                h->next=new Node(0);
            }
            if(head->random){
                auto it=find(head_list.begin(),head_list.end(),head->random);
                if(it!=head_list.end()){
                    map.push_back(make_pair(h, it-head_list.begin()));
                }
                h->random=new Node(0);
            }else{
                map.push_back(make_pair(h, -1));
            }
            head=head->next;
            h=h->next;
        }
        int count=0;
        while(res1){
            if(map[count].second!=-1){
                res1->random=map[map[count].second].first;
            }
            count++;
            res1=res1->next;
        }
        return res2;
    }
};
