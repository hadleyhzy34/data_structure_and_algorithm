//
//  160_intersection_of_two_linked_lists.cpp
//  leetcode_linked_list
//
//  Created by Hadley on 25.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "83_Remove_duplicats_from_sorted_list.cpp"
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>map;
        while(headA){
            map[headA]++;
            headA=headA->next;
        }
        while(headB){
            map[headB]++;
            if(map[headB]==2)break;
            headB=headB->next;
        }
        return headB;
    }
};
