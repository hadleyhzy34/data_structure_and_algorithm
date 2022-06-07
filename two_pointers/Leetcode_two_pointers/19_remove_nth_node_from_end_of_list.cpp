//
//  19_remove_nth_node_from_end_of_list.cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t1=new ListNode(0);
        ListNode* t2=new ListNode(0);
        ListNode & dummy=*t1;
        t1->next=head;
        t2->next=head;
        int c1=0,c2=0;
        while(t1){
            if(c2-c1>=n){
                t1=t1->next;
                if(t1)c1++;
            }
            // cout<<c1<<" "<<t1->val<<" "<<c2<<" "<<t2->val<<endl;
            t2=t2->next;
            if(t2)c2++;
            
            cout<<c1<<" "<<c2<<endl;
            if(!t2->next&&c1+n==c2){
                cout<<c1<<" "<<c2<<" "<<t1->val<<endl;
                t1->next=t1->next->next;
                break;
            }
        }
        return dummy.next;
    }
};
